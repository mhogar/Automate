add_library(interface Shell.cxx Version.cxx)

add_subdirectory(Commands)

target_link_libraries(interface PRIVATE commands)
target_include_directories(interface PUBLIC "${PROJECT_SOURCE_DIR}/interface" "${PROJECT_SOURCE_DIR}/include")
