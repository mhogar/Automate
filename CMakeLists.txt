cmake_minimum_required(VERSION 3.19.0)

set(CMAKE_BUILD_TYPE Debug)

project(AUTOMATE)

add_executable(automate main.cxx)

add_subdirectory(Actions)
add_subdirectory(Animation)

target_link_libraries(automate PRIVATE animation)

target_include_directories(automate PUBLIC "${PROJECT_SOURCE_DIR}")
