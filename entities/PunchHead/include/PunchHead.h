#ifndef PUNCHHEAD_H_
#define PUNCHHEAD_H_

#include "DisplacementSensor.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PunchHead* PunchHeadPtr;

PunchHeadPtr PunchHead_init(DisplacementSensorPtr displacement_sensor);

#ifdef __cplusplus
}
#endif

#endif//PUNCHHEAD_H_