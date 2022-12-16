#include "DcMotorController.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_make_sure_the_DcMotorController_interface_is_safe)
{
    void setup()
    {

    }
    
    void teardown()
    { 

    }
};

TEST(Given_we_want_to_make_sure_the_DcMotorController_interface_is_safe, 
    When_setForward_is_called_with_a_NULL_self_Then_we_dont_seg_fault)
{
    DcMotorController_setForward(NULL);
}

TEST(Given_we_want_to_make_sure_the_DcMotorController_interface_is_safe, 
    When_setReverse_is_called_with_a_NULL_self_Then_we_dont_seg_fault)
{
    DcMotorController_setReverse(NULL);
}

TEST(Given_we_want_to_make_sure_the_DcMotorController_interface_is_safe, 
    When_setDutyCycle_is_called_with_a_NULL_self_Then_we_dont_seg_fault)
{
    DcMotorController_setDutyCycle(NULL, 0);
}
