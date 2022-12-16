#include "DcMotorControllerSpy.h"
#include "DcMotorController.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_pass_off_our_spy_as_a_DcMotorController)
{
    DcMotorControllerSpyPtr spy;
    void setup()
    {
        spy = DcMotorControllerSpy_init();
        CHECK_TEXT(spy, "spy should not be NULL"); 
    }
    
    void teardown()
    { 
        DcMotorControllerSpy_destroy(&spy);
    }
};

TEST(Given_we_want_to_pass_off_our_spy_as_a_DcMotorController, 
    When_we_setForward_Then_we_can_getForwardCount)
{
    DcMotorController_setForward((DcMotorControllerPtr)spy);

    CallCount count = DcMotorControllerSpy_getForwardCount(spy);
    CHECK_EQUAL(1, count);
}

TEST(Given_we_want_to_pass_off_our_spy_as_a_DcMotorController, 
    When_we_setReverse_Then_we_can_getReverseCount)
{
    DcMotorController_setReverse((DcMotorControllerPtr)spy);

    CallCount count = DcMotorControllerSpy_getReverseCount(spy);
    CHECK_EQUAL(1, count);
}

TEST(Given_we_want_to_pass_off_our_spy_as_a_DcMotorController, 
    When_we_setDutyCycle_Then_we_can_getDutyCycle)
{
    DcMotorController_setDutyCycle((DcMotorControllerPtr)spy, 50);

    CallCount count = DcMotorControllerSpy_getDutyCycle(spy);
    CHECK_EQUAL(50, count);
}
