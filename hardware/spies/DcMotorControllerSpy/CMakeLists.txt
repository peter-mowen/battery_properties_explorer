set(TEST_SRC
tests/AllTests.cpp
tests/Tests_create_and_destroy.cpp
tests/Tests_spy_on_setForward.cpp
tests/Tests_spy_on_setReverse.cpp
tests/Tests_spy_on_setDutyCycle.cpp
tests/Tests_spy_through_interface.cpp
)

set(SRC
src/DcMotorControllerSpy.c
)

add_executable(Tests_DcMotorControllerSpy
${TEST_SRC}
${SRC}
)

target_link_libraries(Tests_DcMotorControllerSpy CppUTest)
target_link_libraries(Tests_DcMotorControllerSpy interfaces)
target_include_directories(Tests_DcMotorControllerSpy PRIVATE include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include /usr/local/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include /usr/local/include/CppUTest/MemoryLeakDetectorNewMacros.h")
