find_package(SDL2 REQUIRED)

add_library(window SDLWindow.cxx)

target_link_libraries(window PRIVATE "${SDL2_LIBRARIES}")
target_include_directories(window PUBLIC "${PROJECT_SOURCE_DIR}/media" "${PROJECT_SOURCE_DIR}/include" "${SDL2_INCLUDE_DIR}")

