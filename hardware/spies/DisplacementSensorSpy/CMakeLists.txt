set(TEST_SRC
tests/AllTests.cpp
tests/Tests.cpp
)

set(SRC
src/DisplacementSensorSpy.c
)

set(HEADERS
${CMAKE_CURRENT_SOURCE_DIR}/include/DisplacementSensorSpy.h
)

add_executable(Tests_DisplacementSensorSpy
${TEST_SRC}
${SRC})

target_link_libraries(Tests_DisplacementSensorSpy CppUTest)
target_link_libraries(Tests_DisplacementSensorSpy interfaces)
target_include_directories(Tests_DisplacementSensorSpy PRIVATE include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include /usr/local/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include /usr/local/include/CppUTest/MemoryLeakDetectorNewMacros.h")
