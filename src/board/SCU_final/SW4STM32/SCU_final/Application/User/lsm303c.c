/*
 * lsm303c.c
 *
 *  Created on: 6 июн. 2019 г.
 *      Author: sereshotes
 */


#include "lsm303c.h"


// ===========================================
// Common macro
// ===========================================
#define LSM303C_SET_BITS(reg_data, bitname, data) \
                ((reg_data & ~(bitname##_MSK)) | \
                (((uint8_t)data << bitname##_POS) & bitname##_MSK))

#define LSM303C_GET_BITS(reg_data, bitname)  ((reg_data & (bitname##_MSK)) >> \
                            (bitname##_POS))

#define LSM303C_MIN(a,b)    ((a < b) ? a : b)

// ==========================================
// Bits defines
//===========================================


//CTRL REG 1
#define LSM303C_M_CTRL_REG1_PM_POS (5)
#define LSM303C_M_CTRL_REG1_PM_MSK (0b11 << 5)

#define LSM303C_M_CTRL_REG1_ODR_POS (2)
#define LSM303C_M_CTRL_REG1_ODR_MSK (0b111 << 2)

//CTRL REG 2
#define LSM303C_M_CTRL_REG2_FS_POS (5)
#define LSM303C_M_CTRL_REG2_FS_MSK (0b11 << 5)

#define LSM303C_M_CTRL_REG2_SOFT_RESET_POS (2)
#define LSM303C_M_CTRL_REG2_SOFT_RESET_MSK (0b1 << 2)

#define LSM303C_M_CTRL_REG2_REBOOT_POS (3)
#define LSM303C_M_CTRL_REG2_REBOOT_MSK (0b1 << 3)

//CTRL REG 3
#define LSM303C_M_CTRL_REG3_MD_POS (0)
#define LSM303C_M_CTRL_REG3_MD_MSK (0b11 << 0)

//CTRL REG 4
#define LSM303C_M_CTRL_REG4_PMZ_POS (0)
#define LSM303C_M_CTRL_REG4_PMZ_MSK (0b11 << 0)

//STATUS REG M
#define LSM303C_M_ZXYDA_POS (3)
#define LSM303C_M_ZXYDA_MSK (0b1 << 3)




/******************************************************************************/
/*************************** START REGISTER MAPPING  **************************/
/******************************************************************************/
/* Acceleration Registers */
#define LSM303C_WHO_AM_I_ADDR             0x0F  /* device identification register */
#define LSM303C_WHO_AM_I_M_VAL            0b00111101
#define LSM303C_WHO_AM_I_A_VAL            0b01000001


#define LSM303C_ACT_THS_A                 0x1E
#define LSM303C_ACT_DUR_A                 0x1F
#define LSM303C_CTRL_REG1_A               0x20  /* Control register 1 acceleration */
#define LSM303C_CTRL_REG2_A               0x21  /* Control register 2 acceleration */
#define LSM303C_CTRL_REG3_A               0x22  /* Control register 3 acceleration */
#define LSM303C_CTRL_REG4_A               0x23  /* Control register 4 acceleration */
#define LSM303C_CTRL_REG5_A               0x24  /* Control register 5 acceleration */
#define LSM303C_CTRL_REG6_A               0x25  /* Control register 6 acceleration */
#define LSM303C_CTRL_REG7_A               0x26  /* Control register 6 acceleration */
#define LSM303C_STATUS_REG_A              0x27  /* Status register acceleration */
#define LSM303C_OUT_X_L_A                 0x28  /* Output Register X acceleration */
#define LSM303C_OUT_X_H_A                 0x29  /* Output Register X acceleration */
#define LSM303C_OUT_Y_L_A                 0x2A  /* Output Register Y acceleration */
#define LSM303C_OUT_Y_H_A                 0x2B  /* Output Register Y acceleration */
#define LSM303C_OUT_Z_L_A                 0x2C  /* Output Register Z acceleration */
#define LSM303C_OUT_Z_H_A                 0x2D  /* Output Register Z acceleration */
#define LSM303C_FIFO_CTRL                 0x2E  /* Fifo control Register acceleration */
#define LSM303C_FIFO_SRC                  0x2F  /* Fifo src Register acceleration */

#define LSM303C_IG_CFG1_A                 0x30  /* Interrupt 1 configuration Register acceleration */
#define LSM303C_IG_SRC1_A                 0x31  /* Interrupt 1 source Register acceleration */
#define LSM303C_IG_THS_X1_A               0x32
#define LSM303C_IG_THS_Y1_A               0x33
#define LSM303C_IG_THS_Z1_A               0x34

#define LSM303C_IG_DUR1_A                 0x32
#define LSM303C_INT1_DURATION_A           0x33  /* Interrupt 1 DURATION register acceleration */

#define LSM303C_INT2_CFG_A                0x34  /* Interrupt 2 configuration Register acceleration */
#define LSM303C_INT2_SOURCE_A             0x35  /* Interrupt 2 source Register acceleration */
#define LSM303C_INT2_THS_A                0x36  /* Interrupt 2 Threshold register acceleration */
#define LSM303C_INT2_DURATION_A           0x37  /* Interrupt 2 DURATION register acceleration */

#define LSM303C_CLICK_CFG_A               0x38  /* Click configuration Register acceleration */
#define LSM303C_CLICK_SOURCE_A            0x39  /* Click 2 source Register acceleration */
#define LSM303C_CLICK_THS_A               0x3A  /* Click 2 Threshold register acceleration */

#define LSM303C_TIME_LIMIT_A              0x3B  /* Time Limit Register acceleration */
#define LSM303C_TIME_LATENCY_A            0x3C  /* Time Latency Register acceleration */
#define LSM303C_TIME_WINDOW_A             0x3D  /* Time window register acceleration */

/* Magnetic field Registers */
#define LSM303C_CTRL_REG1_M               0x20  /* Magnetic control register 1 */
#define LSM303C_CTRL_REG2_M               0x21  /* Magnetic control register 2 */
#define LSM303C_CTRL_REG3_M               0x22  /* Magnetic control register 3 */
#define LSM303C_CTRL_REG4_M               0x23  /* Magnetic control register 4 */
#define LSM303C_CTRL_REG5_M               0x24  /* Magnetic control register 5 */

#define LSM303C_STATUS_REG_M              0x27  /* Magnetic status register M  */

#define LSM303C_OUT_X_L_M                 0x28  /* Output Register X magnetic field */
#define LSM303C_OUT_X_H_M                 0x29  /* Output Register X magnetic field */
#define LSM303C_OUT_Y_L_M                 0x2A  /* Output Register Y magnetic field */
#define LSM303C_OUT_Y_H_M                 0x2B  /* Output Register Y magnetic field */
#define LSM303C_OUT_Z_L_M                 0x2C  /* Output Register Z magnetic field */
#define LSM303C_OUT_Z_H_M                 0x2D  /* Output Register Z magnetic field */

#define LSM303C_TEMP_OUT_L_M              0x2E  /* Temperature Register magnetic field */
#define LSM303C_TEMP_OUT_H_M              0x2F  /* Temperature Register magnetic field */

#define LSM303C_INT_CFG_M                 0x30  /* Axis interrupt configuration        */
#define LSM303C_INT_SRC_M                 0x31  /* Axis interrupt source               */
#define LSM303C_INT_THS_L_M               0x32  /* Interrupt threshold L               */
#define LSM303C_INT_THS_H_M               0x33  /* Interrupt threshold M               */

#define LSM303C_TIMEOUT 100

#define LSM303C_I2C_ADDRESS_M 			  0b00011110
#define LSM303C_I2C_ADDRESS_A 			  0b00011101

/******************************************************************************/
/**************************** END REGISTER MAPPING  ***************************/
/******************************************************************************/

static int lsm303c_m_do_read_regn_i2c(const  struct lsm303c_handler_s * priv, uint8_t regaddr,
        uint8_t * data, size_t datasize)
{
	int rc = HAL_I2C_Mem_Read(priv->setup_conf.iface.i2c.hi2c ,priv->setup_conf.iface.i2c.addr_m,
				regaddr, I2C_MEMADD_SIZE_8BIT, data, datasize, LSM303C_TIMEOUT);
	if(rc)
		my_debug("ERROR: can't read i2c lsm303c: %d\n", rc);
	return rc;
}


static int lsm303c_m_do_write_regn_i2c( struct lsm303c_handler_s * priv, uint8_t regaddr,
        uint8_t * data, size_t datasize)
{
	int rc = HAL_I2C_Mem_Write(priv->setup_conf.iface.i2c.hi2c ,priv->setup_conf.iface.i2c.addr_m,
			regaddr, I2C_MEMADD_SIZE_8BIT, data, datasize, LSM303C_TIMEOUT);

	if(rc)
		my_debug("ERROR: can't write i2c lsm303c: %d\n", rc);
	return rc;
}

uint8_t lsm303c_who_am_i(struct lsm303c_handler_s * handler)
{
	uint8_t res = 0;
	handler->read_regn(handler, LSM303C_WHO_AM_I_ADDR, &res, 1);
	return res;
}
// send mag settings to device
int lsm303c_m_push_conf(const struct lsm303c_handler_s *handler,
        const struct lsm303c_m_conf_s * m_conf)
{
    uint8_t creg[5];
    handler->read_regn(handler, LSM303C_CTRL_REG1_M, creg, 5);

    creg[0] = LSM303C_SET_BITS(creg[0], LSM303C_M_CTRL_REG1_ODR, m_conf->odr);
    creg[0] = LSM303C_SET_BITS(creg[0], LSM303C_M_CTRL_REG1_PM, m_conf->pm);

    creg[1] = LSM303C_SET_BITS(creg[1], LSM303C_M_CTRL_REG2_FS, m_conf->fs);

    creg[2] = LSM303C_SET_BITS(creg[2], LSM303C_M_CTRL_REG3_MD, m_conf->md);

    handler->write_regn(handler, LSM303C_CTRL_REG1_M, creg, 5);
    return 0;

}

// read raw mag values
int lsm303c_m_pull(const struct lsm303c_handler_s *handler,
        struct lsm303c_raw_data_m_s * m_raw)
{
    int rc = handler->read_regn(handler, LSM303C_OUT_X_L_M, (uint8_t*)m_raw, 6);
    return rc;
}

void lsm303c_scale_m(const struct lsm303c_handler_s *handler, int16_t *in, float *out, int count)
{
    float k = 1;
    switch(handler->conf.m.fs)
    {
    case LSM303C_M_FS_16_GAUSS:
        k = 16.0;
        break;
    }

    for(int i = 0; i < count; i++)
    {
        out[i] = in[i] / k;
    }
}
void lsm303c_m_conf_default(struct lsm303c_handler_s * handler)
{
    handler->conf.m.fs = LSM303C_M_FS_16_GAUSS;
    handler->conf.m.md = LSM303C_M_MD_CONT_CONV;
    handler->conf.m.odr = LSM303C_M_ODR_80_HZ;
    handler->conf.m.pm = LSM303C_M_PM_ULTRA_HIGH_PERFORMANCE;
}
// registration of device on i2c bus
int lsm303c_register_i2c(struct lsm303c_handler_s * handler, I2C_HandleTypeDef* hi2c)
{
	handler->read_regn =  lsm303c_m_do_read_regn_i2c;
	handler->write_regn =  lsm303c_m_do_write_regn_i2c;
	handler->setup_conf.iface.i2c.hi2c = hi2c;

	handler->setup_conf.iface.i2c.addr_a = LSM303C_I2C_ADDRESS_A << 1;
	handler->setup_conf.iface.i2c.addr_m = LSM303C_I2C_ADDRESS_M << 1;
	int res = lsm303c_who_am_i(handler);

	switch(res)
	{
	case LSM303C_WHO_AM_I_A_VAL:
		my_debug("I'm Accel on lsm303c!\n\n");
		break;
	case LSM303C_WHO_AM_I_M_VAL:
		my_debug("I'm Mag on lsm303c!\n\n");
		break;
	default:
		my_debug("ERROR: unknown device instead of lsm303c\n");
	}

	return 0;
}









/*
// push fifo config to device
// its assumed that device (or at least fifo) is halted
int lsm303c_fifo_push_conf(const struct lsm303c_handler_s *handler,
        const struct lsm303c_fifo_conf_s * fifo_conf);

// get full status of fifo
int lsm303c_fifo_pull_status(const struct lsm303c_handler_s *priv,
        struct lsm303c_fifo_status_s * status);

// read data from device to local buffer
// reading in terms of struct lsm303c_raw_data elems
ssize_t lsm303c_fifo_pull_data(const struct lsm303c_handler_s * priv,
        uint16_t * buffer, size_t buffersize16, size_t size_factor);

int lsm303c_push_conf(struct lsm303c_handler_s *handler);*/
