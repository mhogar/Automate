cmake_minimum_required(VERSION 3.16.0)

option(Debug "Debug" OFF)

if(Debug)
    message(STATUS "Configuring for Debug mode.")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(STATUS "Configuring for Release mode.")
    set(CMAKE_BUILD_TYPE Release)
endif()

project(automate VERSION 0.1.0)

add_executable(automate main.cxx Animation.cxx)

add_subdirectory(Animators)
add_subdirectory(Actors)
add_subdirectory(Actions)
add_subdirectory(Renderers)

target_link_libraries(automate PRIVATE animators actors actions renderers)
target_include_directories(automate PUBLIC "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../include")
