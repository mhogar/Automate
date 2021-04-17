add_library(commands Command.cxx BasicCommands.cxx)
target_include_directories(interface PUBLIC "${PROJECT_SOURCE_DIR}/interface/Shell" "${PROJECT_SOURCE_DIR}/include")
