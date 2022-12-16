#include "DcMotorControllerSpy.h"
#include "DcMotorController_private.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

struct DcMotorControllerInterface interface = 
{
    DcMotorControllerSpy_setForward,
    DcMotorControllerSpy_setReverse,
    DcMotorControllerSpy_setDutyCycle
};

typedef struct motor_controller_spy
{
    DcMotorController base;
    DutyCycle duty_cycle;
    CallCount num_of_setForward_calls;
    CallCount num_of_setReverse_calls;
} DcMotorControllerSpy;


void increment_call_count(CallCount *pCount);
bool duty_cycle_is_valid(DutyCycle duty_cycle);

DcMotorControllerSpyPtr DcMotorControllerSpy_init()
{
    DcMotorControllerSpyPtr self = 
        (DcMotorControllerSpyPtr)malloc(sizeof(DcMotorControllerSpy));

    if (self == NULL) return NULL;

    self->base.vtable = &interface;

    self->duty_cycle = DUTY_CYCLE_NOT_SET;

    self->num_of_setForward_calls = 0;
    self->num_of_setReverse_calls = 0;

    return self;
}

void DcMotorControllerSpy_destroy(DcMotorControllerSpyPtr *pSelf)
{
    if (pSelf == NULL) return;
    free(*pSelf);
    *pSelf = NULL;
}



void DcMotorControllerSpy_setForward(DcMotorControllerPtr self)
{
    if (self == NULL) return;

    DcMotorControllerSpyPtr spy = (DcMotorControllerSpyPtr)self;

    increment_call_count(&spy->num_of_setForward_calls);
}

void DcMotorControllerSpy_setReverse(DcMotorControllerPtr self)
{
    if (self == NULL) return;

    DcMotorControllerSpyPtr spy = (DcMotorControllerSpyPtr)self;

    increment_call_count(&spy->num_of_setReverse_calls);
}

void increment_call_count(CallCount *pCount)
{
    (*pCount)++;

    if (*pCount > MAX_CALL_COUNT)
    {
        *pCount = 0;
    }
}


void DcMotorControllerSpy_setDutyCycle(DcMotorControllerPtr self, DutyCycle duty_cycle)
{
    if (self == NULL) return;

    DcMotorControllerSpyPtr spy = (DcMotorControllerSpyPtr)self;

    if (!duty_cycle_is_valid(duty_cycle))
    {
        spy->duty_cycle = INVAL_DUTY_CYCLE;
        return;
    }

    spy->duty_cycle = duty_cycle;
}

bool duty_cycle_is_valid(DutyCycle duty_cycle)
{
    return 0 <= duty_cycle && duty_cycle <= 100;
}



CallCount DcMotorControllerSpy_getForwardCount(DcMotorControllerSpyPtr self)
{
    if (self == NULL) return NULL_PTR_CALL_COUNT;
    
    return self->num_of_setForward_calls;
}

CallCount DcMotorControllerSpy_getReverseCount(DcMotorControllerSpyPtr self)
{
    if (self == NULL) return NULL_PTR_CALL_COUNT;

    return self->num_of_setReverse_calls;
}

DutyCycle DcMotorControllerSpy_getDutyCycle(DcMotorControllerSpyPtr self)
{
    if (self == NULL) return NULL_PTR_DUTY_CYCLE;
    
    return self->duty_cycle;
}
