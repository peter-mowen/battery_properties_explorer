#ifndef DISPLACEMENT_SENSOR_H_
#define DISPLACEMENT_SENSOR_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//TODO: Add documentation

typedef struct DisplacementSensor* DisplacementSensorPtr;

typedef int32_t Micrometers;
#define MAX_MICROMETERS INT32_MAX
#define SIZE_OF_MM_ARRAY(array) sizeof(array)/sizeof(Micrometers)

Micrometers DisplacementSensor_readMicrometers(DisplacementSensorPtr self);

#ifdef __cplusplus
}
#endif

#endif//DISPLACEMENT_SENSOR_H_