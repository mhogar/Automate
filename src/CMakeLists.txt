cmake_minimum_required(VERSION 3.16.0)

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

include(GNUInstallDirs)

add_library(automate-core SHARED Animation.cxx)

FILE(GLOB PUBLIC_API ../include/*.h)
set_target_properties(automate-core PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${PUBLIC_API}")

add_subdirectory(Animators)
add_subdirectory(Actors)
add_subdirectory(Actions)
add_subdirectory(Renderers)

target_link_libraries(automate-core PRIVATE animators actors actions renderers)
target_include_directories(automate-core PUBLIC "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../include")

install(TARGETS automate-core
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Automate/v${PROJECT_VERSION_MAJOR})
