cmake_minimum_required(VERSION 3.25)

project(BatterPropertiesExplorer)

# Add CppUTest libary to project
find_library(cpputest_location NAMES libCppUTest.a)

add_library(CppUTest STATIC IMPORTED)
set_target_properties(CppUTest PROPERTIES IMPORTED_LOCATION ${cpputest_location})

# Add project subdirs
add_subdirectory(hardware)
add_subdirectory(control_logic)
add_subdirectory(entities)
