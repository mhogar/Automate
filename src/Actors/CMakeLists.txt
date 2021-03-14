add_library(actors Actor.cxx BoxActor.cxx ActorData.h BoxData.h)
target_include_directories(actors PUBLIC "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../include")
