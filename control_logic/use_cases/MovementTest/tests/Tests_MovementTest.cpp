#include "DisplacementSensorSpy.h"
#include "PunchHead.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_run_the_MovementTest)
{
    void setup()
    {

    }
    
    void teardown()
    { 

    }
};

TEST(Given_we_want_to_run_the_MovementTest, 
    Then_this_first_test_fails)
{   
    DisplacementSensorSpyPtr displacement_sensor_spy = NULL;
    PunchHeadPtr punchhead = PunchHead_init((DisplacementSensorPtr)displacement_sensor_spy);
}
