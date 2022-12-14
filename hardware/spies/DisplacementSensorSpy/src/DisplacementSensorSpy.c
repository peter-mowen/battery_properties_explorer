#include "DisplacementSensorSpy.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "DisplacementSensor_private.h"

struct DisplacementSensorInterface interface = 
{
    DisplacementSensorSpy_readMicrometers
};

typedef struct DisplacementSensorSpy
{
    DisplacementSensor base;
    uint8_t num_of_reads;
    Micrometers *readings;
    uint8_t readings_read_index;
} DisplacementSensorSpy;

DisplacementSensorSpyPtr DisplacementSensorSpy_init(Micrometers *readings, uint8_t num_of_readings)
{
    if (readings == NULL || num_of_readings == 0) return NULL;

    DisplacementSensorSpyPtr self = 
        (DisplacementSensorSpyPtr)malloc(sizeof(DisplacementSensorSpy));

    if (self == NULL) return NULL;

    self->num_of_reads = num_of_readings;

    self->readings = (Micrometers*)malloc((self->num_of_reads)*sizeof(Micrometers));

    if (self->readings == NULL)
    {
        DisplacementSensorSpy_destroy(&self);
        return NULL;
    }

    memcpy(self->readings, readings, (self->num_of_reads)*sizeof(Micrometers));

    self->readings_read_index = 0;

    self->base.vtable = &interface;

    return self;
}

void DisplacementSensorSpy_destroy(DisplacementSensorSpyPtr *pSelf)
{
    if (pSelf == NULL || *pSelf == NULL) return; 
    free((*pSelf)->readings);
    free(*pSelf);
    *pSelf = NULL;
}

Micrometers DisplacementSensorSpy_readMicrometers(DisplacementSensorPtr self)
{    
    if (self == NULL) return MAX_MICROMETERS;

    DisplacementSensorSpyPtr spy = (DisplacementSensorSpyPtr)self;

    Micrometers reading = spy->readings[spy->readings_read_index];
    
    spy->readings_read_index++;

    if (spy->readings_read_index >= spy->num_of_reads)
    {
        spy->readings_read_index = 0;
    }

    return reading;
}
