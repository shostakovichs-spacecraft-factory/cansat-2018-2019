
#include <inttypes.h>

#include <stm32f10x.h>
#include <diag/Trace.h>

#include "i2c.h"
#include "ina219.h"



int main()
{
    i2c_init_bus1();

    int error = 0;
    ina219_t ina;
    ina219_init(&ina, I2C1, INA219_I2CADDR_A1_GND_A0_GND);
    error = ina219_sw_reset(&ina);
    trace_printf("reset error %d\n", error);
    // подождем после резета
    for (volatile int x = 0; x < 1000000; x++) {}

    uint16_t cfgreg;
    ina219_read_reg(&ina, 0x00, &cfgreg);
    trace_printf("cfgreg:0x%04" PRIX16 "\n", cfgreg);
    for (volatile int x = 0; x < 5000000; x++) {}

    ina219_cfg_t ina_cfg;
    ina_cfg.bus_range = INA219_BUS_RANGE_16V;
    ina_cfg.bus_res = INA219_ADC_RES_12_BIT_OVS_1;
    ina_cfg.shunt_range = INA219_SHUNT_RANGE_80MV;
    ina_cfg.shunt_res = INA219_ADC_RES_12_BIT_OVS_1;
    ina_cfg.mode = INA219_MODE_SHUNT_AND_BUS_CONT;


    ina_cfg.shunt_r = 0.1f; // 100 миллиом
    ina_cfg.current_lsb = 1.f/0x8000; // считаем из расчета на 1 ампер максимум
    //error = ina219_set_cfg(&ina, &ina_cfg);
    trace_printf("set_cfg error %d\n", error);


    while(1)
    {
        ina219_primary_data_t prim_data;

        error = ina219_read_primary(&ina, &prim_data);
        int32_t shunt_mv = prim_data.shuntv*INA219_SHUNTV_LSB_MKV/1000;
        int32_t bus_mv = prim_data.busv*INA219_BUSV_LSB_MV;
        trace_printf("error %d shunt-raw:%" PRId16 " bus-raw:%" PRIu16 " shunt:%d bus:%d: cnvr:%d ovf:%d\n",
                error,
                prim_data.shuntv, prim_data.busv,
                shunt_mv, bus_mv,
                prim_data.cnvr, prim_data.ovf
        );

        uint16_t cfgreg;
        ina219_read_reg(&ina, 0x00, &cfgreg);
        trace_printf("cfgreg:0x%04" PRIX16 "\n", cfgreg);
        for (volatile int x = 0; x < 5000000; x++) {}


        /*
        ina219_primary_data_t prim_data;
        ina219_secondary_data_t sec_data;

        error = ina219_read_all(&ina, &prim_data, &sec_data);
        trace_printf("read_all error %d\n", error);

        trace_printf("prim_data: %" PRId16 " %" PRIu16 " %d %d\n",
                prim_data.shuntv*INA219_SHUNTV_LSB_MV, prim_data.busv*INA219_BUSV_LSB_MV,
                prim_data.cnvr, prim_data.ovf
        );

        trace_printf("sec_data: %" PRIu16 " %" PRIi16 "\n",
                sec_data.power, sec_data.current
        );
        */
    }

    return 0;
}
