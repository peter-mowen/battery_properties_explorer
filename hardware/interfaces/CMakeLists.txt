add_subdirectory(DisplacementSensor)

set(SRC
DisplacementSensor/src/DisplacementSensor.c
)

set(HEADERS
DisplacementSensor/include/DisplacementSensor.h
DisplacementSensor/include/DisplacementSensor_private.h
)

add_library(interfaces STATIC
${SRC} ${HEADERS})

target_include_directories(interfaces PUBLIC DisplacementSensor/include/)