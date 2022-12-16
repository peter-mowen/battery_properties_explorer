set(TEST_SRC
tests/AllTests.cpp
tests/Tests.cpp
)

set(SRC
src/DcMotorController.c
)

set(HEADERS
${CMAKE_CURRENT_SOURCE_DIR}/include/DcMotorController.h
${CMAKE_CURRENT_SOURCE_DIR}/include/DcMotorController_private.h
)

add_executable(Tests_DcMotorController
${TEST_SRC}
${SRC}
)

target_link_libraries(Tests_DcMotorController CppUTest)
target_include_directories(Tests_DcMotorController PRIVATE include)