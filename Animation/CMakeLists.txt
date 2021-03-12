add_library(animation Animation.cxx RootAnimator.cxx ActorAnimator.cxx)

target_link_libraries(animation PRIVATE actors)
target_include_directories(animation PUBLIC "${PROJECT_SOURCE_DIR}")
