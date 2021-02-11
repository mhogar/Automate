cmake_minimum_required(VERSION 3.19.0)

option(Debug "Debug" OFF)

if(DEBUG)
    message(STATUS "Configuring for Debug mode.")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(STATUS "Configuring for Release mode.")
    set(CMAKE_BUILD_TYPE Release)
endif()

project(AUTOMATE)

add_executable(automate main.cxx)

add_subdirectory(Actions)
add_subdirectory(SDL2Impl)
add_subdirectory(Animation)

target_link_libraries(automate PRIVATE automate-core)

target_include_directories(automate PUBLIC "${PROJECT_SOURCE_DIR}")
