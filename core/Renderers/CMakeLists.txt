add_library(renderers LogRenderer.cxx)
target_include_directories(renderers PUBLIC "${PROJECT_SOURCE_DIR}/core" "${PROJECT_SOURCE_DIR}/include")
