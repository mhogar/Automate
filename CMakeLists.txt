cmake_minimum_required(VERSION 3.18.0)
set(CMAKE_CXX_STANDARD 17)

option(Debug "Debug" OFF)

if(Debug)
    message(STATUS "Configuring for Debug mode.")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(STATUS "Configuring for Release mode.")
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(automate VERSION 0.1.0)

add_executable(automate main.cxx)

add_subdirectory(common)
add_subdirectory(core)
add_subdirectory(interface)
add_subdirectory(media)

target_link_libraries(automate PRIVATE automate-core automate-ui automate-media)
target_include_directories(automate PUBLIC "${PROJECT_SOURCE_DIR}/include")
