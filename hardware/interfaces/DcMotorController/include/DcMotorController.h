#ifndef DC_MOTOR_CONTROLLER_H_
#define DC_MOTOR_CONTROLLER_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dc_motor_controller* DcMotorControllerPtr;

typedef int8_t DutyCycle;


void DcMotorController_setForward(DcMotorControllerPtr self);

void DcMotorController_setReverse(DcMotorControllerPtr self);

void DcMotorController_setDutyCycle(DcMotorControllerPtr self, DutyCycle duty_cycle);

#ifdef __cplusplus
}
#endif

#endif//DC_MOTOR_CONTROLLER_H_