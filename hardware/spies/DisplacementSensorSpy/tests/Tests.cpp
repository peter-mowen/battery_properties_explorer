#include "DisplacementSensorSpy.h"
#include "DisplacementSensor.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Given_we_want_to_use_a_DisplacementSensorSpy)
{
    DisplacementSensorSpyPtr spy;

    void setup()
    {
        spy = NULL;
    }
    
    void teardown()
    { 
        DisplacementSensorSpy_destroy(&spy);
    }

    void check_expected_reading_from_spy(Micrometers expected_reading, DisplacementSensorSpyPtr spy)
    {
        Micrometers actual_reading = 
            DisplacementSensorSpy_readMicrometers((DisplacementSensorPtr)spy);
        CHECK_EQUAL(expected_reading, actual_reading);
    }
};

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_initialize_the_spy_to_with_0_expected_reads_Then_init_returns_NULL)
{
    Micrometers readings[1] = {1};
    DisplacementSensorSpyPtr local_spy = DisplacementSensorSpy_init(readings, 0);
    POINTERS_EQUAL(NULL, local_spy);
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_initialize_the_spy_to_with_NULL_readings_Then_init_returns_NULL)
{
    DisplacementSensorSpyPtr local_spy = DisplacementSensorSpy_init(NULL, 1);
    POINTERS_EQUAL(NULL, local_spy);
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_destroy_a_spy_Then_the_spy_gets_freed_and_set_to_NULL)
{
    Micrometers readings[1] = {1};
    DisplacementSensorSpyPtr local_spy = 
        DisplacementSensorSpy_init(readings, SIZE_OF_MM_ARRAY(readings));
    CHECK_TEXT(local_spy, "local_spy should not be NULL");

    DisplacementSensorSpy_destroy(&local_spy);
    POINTERS_EQUAL_TEXT(NULL, local_spy, "local_spy should be NULL after being destroyed");
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_pass_NULL_to_destory_Then_we_dont_segfault)
{
    DisplacementSensorSpy_destroy(NULL);
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_pass_a_pointer_to_NULL_to_destory_Then_we_dont_segfault)
{
    DisplacementSensorSpyPtr local_spy = NULL;
    DisplacementSensorSpy_destroy(&local_spy);
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_initialize_the_spy_to_have_1_read_Then_we_can_set_and_get_1_read)
{
    Micrometers readings[1] = {1};
    spy = DisplacementSensorSpy_init(readings, SIZE_OF_MM_ARRAY(readings));
    CHECK_TEXT(spy, "spy should not be NULL");

    check_expected_reading_from_spy(1, spy);
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_initialize_the_spy_to_have_2_readings_Then_we_get_the_readings_in_the_array_order)
{
    Micrometers readings[2] = {9, 19};
    spy = DisplacementSensorSpy_init(readings, SIZE_OF_MM_ARRAY(readings));
    CHECK_TEXT(spy, "spy should not be NULL");

    check_expected_reading_from_spy(9, spy);
    check_expected_reading_from_spy(19, spy);

}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_initialize_the_spy_with_an_arbitrary_number_of_readings_Then_we_get_the_readings_in_the_array_order)
{
    Micrometers pi[5] = {3, 1, 4, 1, 5};
    spy = DisplacementSensorSpy_init(pi, SIZE_OF_MM_ARRAY(pi));
    CHECK_TEXT(spy, "spy should not be NULL");

    check_expected_reading_from_spy(3, spy);
    check_expected_reading_from_spy(1, spy);
    check_expected_reading_from_spy(4, spy);
    check_expected_reading_from_spy(1, spy);
    check_expected_reading_from_spy(5, spy);
    
    DisplacementSensorSpy_destroy(&spy);

    Micrometers sqrtOf2[11] = {1, 4, 1, 4, 2, 1, 3, 5, 6, 2, 3};
    spy = DisplacementSensorSpy_init(sqrtOf2, SIZE_OF_MM_ARRAY(sqrtOf2));
    CHECK_TEXT(spy, "spy should not be NULL");

    check_expected_reading_from_spy(1, spy);
    check_expected_reading_from_spy(4, spy);
    check_expected_reading_from_spy(1, spy);
    check_expected_reading_from_spy(4, spy);
    check_expected_reading_from_spy(2, spy);
    check_expected_reading_from_spy(1, spy);
    check_expected_reading_from_spy(3, spy);
    check_expected_reading_from_spy(5, spy);
    check_expected_reading_from_spy(6, spy);
    check_expected_reading_from_spy(2, spy);
    check_expected_reading_from_spy(3, spy);

}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_pass_readMicrometers_a_NULL_DisplacementSensor_Then_it_returns_MAX_MICROMETER)
{
    CHECK_EQUAL(MAX_MICROMETERS, DisplacementSensorSpy_readMicrometers(NULL));
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    When_we_perform_more_reads_than_num_of_readings_Then_it_circles_back_around_to_the_first)
{
    Micrometers white_sock[2] = {23, 19};
    spy = DisplacementSensorSpy_init(white_sock, SIZE_OF_MM_ARRAY(white_sock));
    CHECK_TEXT(spy, "spy should not be NULL");

    check_expected_reading_from_spy(23, spy);
    check_expected_reading_from_spy(19, spy);
    check_expected_reading_from_spy(23, spy);
}

TEST(Given_we_want_to_use_a_DisplacementSensorSpy, 
    Then_we_can_get_a_reading_from_our_spy_through_the_DisplacementSensor_read_function)
{
    Micrometers e[2] = {271, 828};
    spy = DisplacementSensorSpy_init(e, SIZE_OF_MM_ARRAY(e));
    CHECK_TEXT(spy, "spy should not be NULL");

    Micrometers actual_reading = 
        DisplacementSensor_readMicrometers((DisplacementSensorPtr)spy);
    CHECK_EQUAL(271, actual_reading);

    actual_reading = 
        DisplacementSensor_readMicrometers((DisplacementSensorPtr)spy);
    CHECK_EQUAL(828, actual_reading);
}
