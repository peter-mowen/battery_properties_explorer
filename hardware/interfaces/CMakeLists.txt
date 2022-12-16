add_subdirectory(DisplacementSensor)
add_subdirectory(DcMotorController)

set(SRC
DisplacementSensor/src/DisplacementSensor.c
DcMotorController/src/DcMotorController.c
)

set(HEADERS
DisplacementSensor/include/DisplacementSensor.h
DisplacementSensor/include/DisplacementSensor_private.h
DcMotorController/include/DcMotorController.h
DcMotorController/include/DcMotorController.h
)

add_library(interfaces STATIC
${SRC} ${HEADERS})

target_include_directories(interfaces PUBLIC 
DisplacementSensor/include/
DcMotorController/include/
)