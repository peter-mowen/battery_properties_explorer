set(TEST_SRC
PunchHead/tests/AllTests.cpp
PunchHead/tests/Tests.cpp
)

set(SRC
PunchHead/src/PunchHead.c
)

add_executable(Tests_PunchHead
${TEST_SRC} ${SRC}
)

target_include_directories(Tests_PunchHead PRIVATE PunchHead/include)

target_link_libraries(Tests_PunchHead CppUTest)
target_link_libraries(Tests_PunchHead HardwareSpies)
target_link_libraries(Tests_PunchHead interfaces)

add_library(bpxEntities STATIC
PunchHead/include/PunchHead.h
PunchHead/src/PunchHead.c
)

target_include_directories(bpxEntities 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/PunchHead/include
)

target_link_libraries(bpxEntities PUBLIC interfaces)