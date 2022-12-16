#include "DcMotorControllerSpy.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_spy_on_setDutyCycle)
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

TEST(Given_we_want_to_spy_on_setDutyCycle, 
    When_we_do_not_set_the_duty_cycle_Then_getDutyCycle_returns_DUTY_CYCLE_NOT_SET)
{
    DutyCycle duty_cycle = DcMotorControllerSpy_getDutyCycle(spy);

    CHECK_EQUAL(DUTY_CYCLE_NOT_SET, duty_cycle);
}

TEST(Given_we_want_to_spy_on_setDutyCycle, 
    When_we_setDutyCycle_Then_getDutyCycle_returns_what_we_set)
{
    DcMotorControllerSpy_setDutyCycle((DcMotorControllerPtr)spy, 50);
    DutyCycle duty_cycle = DcMotorControllerSpy_getDutyCycle(spy);

    CHECK_EQUAL(50, duty_cycle);
}

TEST(Given_we_want_to_spy_on_setDutyCycle, 
    When_we_try_to_setDutyCycle_of_a_NULL_spy_Then_we_dont_seg_fault)
{
    DcMotorControllerSpy_setDutyCycle(NULL, 0);
}

TEST(Given_we_want_to_spy_on_setDutyCycle, 
    When_we_try_to_getDutyCycle_of_a_NULL_spy_Then_it_returns_NULL_PTR_DUTY_CYLE)
{
    DutyCycle duty_cycle = DcMotorControllerSpy_getDutyCycle(NULL);

    CHECK_EQUAL(NULL_PTR_DUTY_CYCLE, duty_cycle);
}

TEST(Given_we_want_to_spy_on_setDutyCycle, 
    When_we_try_to_set_a_duty_cycle_greater_than_100_Then_getDutyCycle_returns_INVAL_DUTY_CYCLE)
{
    DcMotorControllerSpy_setDutyCycle((DcMotorControllerPtr)spy, 100);
    DutyCycle duty_cycle = DcMotorControllerSpy_getDutyCycle(spy);

    CHECK_EQUAL(100, duty_cycle);

    DcMotorControllerSpy_setDutyCycle((DcMotorControllerPtr)spy, 101);
    duty_cycle = DcMotorControllerSpy_getDutyCycle(spy);

    CHECK_EQUAL(INVAL_DUTY_CYCLE, duty_cycle);
}

TEST(Given_we_want_to_spy_on_setDutyCycle, 
    When_we_try_to_set_a_duty_cycle_less_than_0_Then_getDutyCycle_returns_INVAL_DUTY_CYCLE)
{
    DcMotorControllerSpy_setDutyCycle((DcMotorControllerPtr)spy, 0);
    DutyCycle duty_cycle = DcMotorControllerSpy_getDutyCycle(spy);

    CHECK_EQUAL(0, duty_cycle);

    DcMotorControllerSpy_setDutyCycle((DcMotorControllerPtr)spy, -1);
    duty_cycle = DcMotorControllerSpy_getDutyCycle(spy);

    CHECK_EQUAL(INVAL_DUTY_CYCLE, duty_cycle);
}
