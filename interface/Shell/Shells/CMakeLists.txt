add_library(shells Shell.cxx BaseShell.cxx PreviewShell.cxx GPUShell.cxx)
target_include_directories(shells PUBLIC "${PROJECT_SOURCE_DIR}/interface/Shell" "${PROJECT_SOURCE_DIR}/media" "${PROJECT_SOURCE_DIR}/include")
