set(TEST_SRC
tests/AllTests.cpp
tests/Tests.cpp
)

set(SRC
src/DisplacementSensor.c
)

set(HEADERS
${CMAKE_CURRENT_SOURCE_DIR}/include/DisplacementSensor.h
${CMAKE_CURRENT_SOURCE_DIR}/include/DisplacementSensor_private.h
)

add_executable(Tests_DisplacementSensor
${TEST_SRC}
${SRC})

target_link_libraries(Tests_DisplacementSensor CppUTest)
target_include_directories(Tests_DisplacementSensor PRIVATE include)