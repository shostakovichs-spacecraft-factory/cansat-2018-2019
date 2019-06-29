#ifndef SENSORS_H_
#define SENSORS_H_

//Inits BME280, DS18B20, MPX2100AP (and also I2C1, OneWire and ADS1115 required for them)
void sensors_init(void);

//Read data from BME280 sensor and send scaled_pressure MAVLink message
void sensors_bme280_update(void);

//Read data from DS18B20 and MPX2100AP sensors and send scaled_pressure2 MAVLink message
void sensors_external_update(void);

#endif //#ifndef SENSORS_H_
