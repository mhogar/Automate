find_package(SDL2 REQUIRED)

add_library(animation Animation.cxx AnimationBuilder.cxx AnimationRenderer.cxx SDLFacade.cxx)

target_link_libraries(animation PRIVATE actions ${SDL2_LIBRARIES})
target_include_directories(animation PUBLIC "${PROJECT_SOURCE_DIR}" "${SDL2_INCLUDE_DIRS}")
