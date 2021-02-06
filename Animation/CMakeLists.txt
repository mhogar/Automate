add_library(animation Animation.cxx AnimationBuilder.cxx AnimationRenderer.cxx)

target_link_libraries(animation PRIVATE actions)

target_include_directories(animation PUBLIC "${PROJECT_SOURCE_DIR}")
