#ifndef DC_MOTOR_CONTROLLER_PRIVATE_H_
#define DC_MOTOR_CONTROLLER_PRIVATE_H_

#include "DcMotorController.h"

#ifdef __cplusplus
extern "C" {
#endif

struct DcMotorControllerInterface
{
    void (*setForward)(DcMotorControllerPtr self);
    void (*setReverse)(DcMotorControllerPtr self);
    void (*setDutyCycle)(DcMotorControllerPtr self, DutyCycle duty_cycle);
};

typedef struct DcMotorControllerInterface* DcMotorControllerInterfacePtr;

typedef struct dc_motor_controller
{
    DcMotorControllerInterfacePtr vtable;
} DcMotorController;

#ifdef __cplusplus
}
#endif

#endif//DC_MOTOR_CONTROLLER_PRIVATE_H_