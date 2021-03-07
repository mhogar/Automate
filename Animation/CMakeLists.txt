add_library(animation AnimationRenderer.cxx)

target_link_libraries(animation PRIVATE actors)
target_include_directories(animation PUBLIC "${PROJECT_SOURCE_DIR}")
