#ifndef MOTOR_CONTROLLER_SPY_H_
#define MOTOR_CONTROLLER_SPY_H_

#include "DcMotorController.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct motor_controller_spy* DcMotorControllerSpyPtr;

typedef uint8_t CallCount;
#define NULL_PTR_CALL_COUNT     UINT8_MAX
#define MAX_CALL_COUNT          NULL_PTR_CALL_COUNT-1

#define DUTY_CYCLE_NOT_SET -1
#define NULL_PTR_DUTY_CYCLE -2
#define INVAL_DUTY_CYCLE -3

DcMotorControllerSpyPtr DcMotorControllerSpy_init();

void DcMotorControllerSpy_destroy(DcMotorControllerSpyPtr *pSelf);


void DcMotorControllerSpy_setForward(DcMotorControllerPtr self);

void DcMotorControllerSpy_setReverse(DcMotorControllerPtr self);

void DcMotorControllerSpy_setDutyCycle(DcMotorControllerPtr self, DutyCycle duty_cycle);


CallCount DcMotorControllerSpy_getForwardCount(DcMotorControllerSpyPtr self);

CallCount DcMotorControllerSpy_getReverseCount(DcMotorControllerSpyPtr self);

DutyCycle DcMotorControllerSpy_getDutyCycle(DcMotorControllerSpyPtr self);

#ifdef __cplusplus
}
#endif

#endif//MOTOR_CONTROLLER_SPY_H_