find_package(SDL2 REQUIRED)

add_library(sdl2imp SDLGraphicsImpl.cxx)

target_link_libraries(sdl2imp PRIVATE ${SDL2_LIBRARIES})
target_include_directories(sdl2imp PUBLIC "${PROJECT_SOURCE_DIR}" "${SDL2_INCLUDE_DIRS}")
