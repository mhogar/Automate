add_library(interface Shell.cxx)
target_include_directories(interface PUBLIC "${PROJECT_SOURCE_DIR}/interface" "${PROJECT_SOURCE_DIR}/include")
