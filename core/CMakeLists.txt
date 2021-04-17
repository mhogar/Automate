set(LIB_NAME Core)
set(LIB_CODE_VERSION 0.1.0)
set(LIB_API_VERSION 0.1.0)

file(READ "${PROJECT_SOURCE_DIR}/tmpl/Version.cxx.tmpl" VERSION_FILE_TMPL)
file(CONFIGURE OUTPUT "${PROJECT_SOURCE_DIR}/core/Version.cxx" 
        CONTENT "${VERSION_FILE_TMPL}"
        NEWLINE_STYLE UNIX)

add_library(automate-core SHARED Animation.cxx Version.cxx)
set_target_properties(automate-core PROPERTIES
    VERSION ${LIB_CODE_VERSION})

add_subdirectory(Animators)
add_subdirectory(Actors)
add_subdirectory(Actions)
add_subdirectory(Renderers)

target_link_libraries(automate-core PRIVATE animators actors actions renderers)
target_include_directories(automate-core PUBLIC "${PROJECT_SOURCE_DIR}/core" "${PROJECT_SOURCE_DIR}/include")
