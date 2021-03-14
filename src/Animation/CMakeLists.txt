add_library(animation Animation.cxx ActorAnimator.cxx)
target_include_directories(animation PUBLIC "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../include")
