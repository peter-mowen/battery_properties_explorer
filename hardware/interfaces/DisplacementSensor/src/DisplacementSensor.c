#include "DisplacementSensor.h"
#include "DisplacementSensor_private.h"

#include <stdio.h>

Micrometers DisplacementSensor_readMicrometers(DisplacementSensorPtr self)
{
    if (self == NULL) return MAX_MICROMETERS;
    return self->vtable->readMicrometers(self);
}
