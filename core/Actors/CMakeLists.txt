add_library(actors Actor.cxx BoxActor.cxx)
target_include_directories(actors PUBLIC "${PROJECT_SOURCE_DIR}/core" "${PROJECT_SOURCE_DIR}/include")
