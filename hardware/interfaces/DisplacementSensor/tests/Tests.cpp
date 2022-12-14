#include "DisplacementSensor.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_make_sure_the_DisplacementSensor_interface_is_safe)
{
    void setup()
    {

    }
    
    void teardown()
    { 

    }
};

TEST(Given_we_want_to_make_sure_the_DisplacementSensor_interface_is_safe, 
    When_we_try_to_read_from_a_NULL_sensor_Then_it_returns_MAX_MICROMETERS)
{
    Micrometers actual_reading = DisplacementSensor_readMicrometers(NULL);
    CHECK_EQUAL(MAX_MICROMETERS, actual_reading);
}
