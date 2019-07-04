#ifndef SENSORS_H_
#define SENSORS_H_





//Read data from BME280 sensor and send scaled_pressure MAVLink message
void sensors_bme280_update(void);

//Read data from DS18B20 and MPX2100AP sensors and send scaled_pressure2 MAVLink message
void sensors_external_update(void);

#endif //#ifndef SENSORS_H_
