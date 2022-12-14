add_subdirectory(DisplacementSensorSpy)

set(SRC
DisplacementSensorSpy/src/DisplacementSensorSpy.c
)

set(HEADERS
DisplacementSensorSpy/include/DisplacementSensorSpy.h
ForceSensorSpy/include/ForceSensorSpy.h
)

add_library(HardwareSpies STATIC
${SRC} ${HEADERS}
)

target_include_directories(HardwareSpies 
    PUBLIC 
    DisplacementSensorSpy/include/
    ForceSensorSpy/include/
)