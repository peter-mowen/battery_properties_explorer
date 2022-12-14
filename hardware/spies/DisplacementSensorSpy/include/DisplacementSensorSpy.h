#ifndef DISPLACEMENT_SENSORY_SPY_H_
#define DISPLACEMENT_SENSORY_SPY_H_

#include "DisplacementSensor.h"

#ifdef __cplusplus
extern "C" {
#endif

//TODO: Add documentation

typedef struct DisplacementSensorSpy* DisplacementSensorSpyPtr;

DisplacementSensorSpyPtr DisplacementSensorSpy_init(Micrometers *readings, uint8_t num_of_readings);

void DisplacementSensorSpy_destroy(DisplacementSensorSpyPtr *pSelf);

Micrometers DisplacementSensorSpy_readMicrometers(DisplacementSensorPtr self);

#ifdef __cplusplus
}
#endif

#endif//DISPLACEMENT_SENSORY_SPY_H_