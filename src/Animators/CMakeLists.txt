add_library(animators ActorAnimator.cxx)
target_include_directories(animators PUBLIC "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../include")
