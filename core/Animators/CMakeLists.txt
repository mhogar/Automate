add_library(animators ActorAnimator.cxx)
target_include_directories(animators PUBLIC "${PROJECT_SOURCE_DIR}/core" "${PROJECT_SOURCE_DIR}/include")
