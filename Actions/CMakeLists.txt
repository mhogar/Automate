add_library(actions Timeline.cxx Action.cxx StdActions.cxx TransformActions.cxx)

target_include_directories(actions PUBLIC "${PROJECT_SOURCE_DIR}")
