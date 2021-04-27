set(LIB_NAME Interface)
set(LIB_CODE_VERSION 0.1.0)
set(LIB_API_VERSION 0.1.0)

file(READ "${PROJECT_SOURCE_DIR}/tmpl/Version.cxx.tmpl" VERSION_FILE_TMPL)
file(CONFIGURE OUTPUT "${PROJECT_SOURCE_DIR}/interface/Version.cxx" 
        CONTENT "${VERSION_FILE_TMPL}"
        NEWLINE_STYLE UNIX)

add_library(automate-ui SHARED ShellInterface.cxx ConsoleInput.cxx ../Version.cxx)
set_target_properties(automate-ui PROPERTIES
    VERSION ${LIB_CODE_VERSION})

add_subdirectory(Shells)

target_link_libraries(automate-ui PRIVATE common shells)
target_include_directories(automate-ui PUBLIC "${PROJECT_SOURCE_DIR}/interface" "${PROJECT_SOURCE_DIR}/include")
