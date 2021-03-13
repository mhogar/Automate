add_library(actions Timeline.cxx Action.cxx ControlActions.cxx TransformActions.cxx)

target_include_directories(actions PUBLIC "${PROJECT_SOURCE_DIR}")
