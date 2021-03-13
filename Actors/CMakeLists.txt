add_library(actors Actor.cxx BoxActor.cxx ActorData.hxx BoxData.hxx)
target_include_directories(actors PUBLIC "${PROJECT_SOURCE_DIR}")
