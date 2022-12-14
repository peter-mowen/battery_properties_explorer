#ifndef DISPLACEMENT_SENSOR_PRIVATE_H_
#define DISPLACEMENT_SENSOR_PRIVATE_H_

#include "DisplacementSensor.h"

//TODO: Add documentation

struct DisplacementSensorInterface
{
    Micrometers (*readMicrometers)(DisplacementSensorPtr self);
};

typedef struct DisplacementSensorInterface* DisplacementSensorInterfacePtr;

typedef struct DisplacementSensor
{
    DisplacementSensorInterfacePtr vtable;
} DisplacementSensor;

#endif//DISPLACEMENT_SENSOR_PRIVATE_H_