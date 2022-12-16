#include "DcMotorControllerSpy.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_create_and_destroy_a_DcMotorControllerSpy)
{
    void setup()
    {

    }
    
    void teardown()
    { 

    }
};

TEST(Given_we_want_to_create_and_destroy_a_DcMotorControllerSpy, 
    Then_we_can_create_and_destroy_the_spy_without_memory_leaks_and_destroying_makes_pointer_NULL)
{
    DcMotorControllerSpyPtr local_spy = DcMotorControllerSpy_init();
    CHECK_TEXT(local_spy, "local_spy should not be NULL");

    DcMotorControllerSpy_destroy(&local_spy);
    POINTERS_EQUAL_TEXT(NULL, local_spy, "local_spy should be NULL after being destroyed");
}

TEST(Given_we_want_to_create_and_destroy_a_DcMotorControllerSpy, 
    When_we_pass_NULL_into_destroy_Then_it_does_not_seg_fault)
{
    DcMotorControllerSpy_destroy(NULL);
}
