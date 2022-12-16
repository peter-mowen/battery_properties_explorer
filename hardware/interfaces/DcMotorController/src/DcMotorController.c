#include "DcMotorController.h"
#include "DcMotorController_private.h"

#include <stddef.h>

void DcMotorController_setForward(DcMotorControllerPtr self)
{
    if (self == NULL) return;

    self->vtable->setForward(self);
}

void DcMotorController_setReverse(DcMotorControllerPtr self)
{
    if (self == NULL) return;

    self->vtable->setReverse(self);
}

void DcMotorController_setDutyCycle(DcMotorControllerPtr self, DutyCycle duty_cycle)
{
    if (self == NULL) return;

    self->vtable->setDutyCycle(self, duty_cycle);
}