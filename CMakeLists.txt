cmake_minimum_required(VERSION 3.24)
project(work_time_calc C)

set(CMAKE_C_STANDARD 11)

#include_directories(.)

add_executable(work_time_calc src/main.c)

install(TARGETS work_time_calc DESTINATION bin)

# uninstall target
if(NOT TARGET uninstall)
    configure_file(
            "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
            "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
            IMMEDIATE @ONLY)

    add_custom_target(uninstall
            COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
