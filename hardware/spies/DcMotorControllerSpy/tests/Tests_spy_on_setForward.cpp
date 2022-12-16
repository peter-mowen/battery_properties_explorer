#include "DcMotorControllerSpy.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_spy_on_setForward)
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

TEST(Given_we_want_to_spy_on_setForward, 
    When_we_call_setForward_with_a_NULL_spy_Then_it_does_not_segfault)
{
    DcMotorControllerSpy_setForward(NULL);
}

TEST(Given_we_want_to_spy_on_setForward, 
    When_we_call_getForwardCount_with_a_NULL_spy_Then_it_returns_NULL_PTR_CALL_COUNT)
{
    CallCount calls = DcMotorControllerSpy_getForwardCount(NULL);

    CHECK_EQUAL(NULL_PTR_CALL_COUNT, calls);
}

TEST(Given_we_want_to_spy_on_setForward, 
    When_we_do_not_call_setForward_Then_getForwardCount_returns_0)
{
    CallCount calls = DcMotorControllerSpy_getForwardCount(spy);

    CHECK_EQUAL(0, calls);
}

TEST(Given_we_want_to_spy_on_setForward, 
    When_we_call_setForward_once_Then_getForwardCount_returns_1)
{
    DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);
    CallCount calls = DcMotorControllerSpy_getForwardCount(spy);

    CHECK_EQUAL(1, calls);
}

TEST(Given_we_want_to_spy_on_setForward, 
    When_we_call_setForward_multiple_times_Then_getForwardCount_returns_the_total_number_of_calls)
{
    DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);
    DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);
    DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);

    CallCount calls = DcMotorControllerSpy_getForwardCount(spy);

    CHECK_EQUAL(3, calls);

    DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);
    DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);
    calls = DcMotorControllerSpy_getForwardCount(spy);
    CHECK_EQUAL(5, calls);
}

TEST(Given_we_want_to_spy_on_setForward, 
    When_we_call_setForward_MAX_CALL_COUNT_plus_one_times_Then_getForwardCount_returns_0)
{
    CallCount num_of_calls;
    for (num_of_calls = 1; num_of_calls <= MAX_CALL_COUNT; num_of_calls++)
    {
        DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);
    }

    CallCount call_count = DcMotorControllerSpy_getForwardCount(spy);
    CHECK_EQUAL_TEXT(MAX_CALL_COUNT, call_count, 
        "we should have called it MAX_CALL_COUNT number of times at this point");

    // plus +1 more call
    DcMotorControllerSpy_setForward((DcMotorControllerPtr)spy);
    
    call_count = DcMotorControllerSpy_getForwardCount(spy);
    CHECK_EQUAL_TEXT(0, call_count,
        "number of calls should have rolled over to 0");
}
