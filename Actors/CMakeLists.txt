add_library(actors RootActor.cxx Actor.cxx BoxActor.cxx)

target_link_libraries(actors PRIVATE actions)
target_include_directories(actors PUBLIC "${PROJECT_SOURCE_DIR}")
