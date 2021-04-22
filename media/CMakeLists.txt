set(LIB_NAME Media)
set(LIB_CODE_VERSION 0.1.0)
set(LIB_API_VERSION 0.1.0)

file(READ "${PROJECT_SOURCE_DIR}/tmpl/Version.cxx.tmpl" VERSION_FILE_TMPL)
file(CONFIGURE OUTPUT "${PROJECT_SOURCE_DIR}/media/Version.cxx" 
        CONTENT "${VERSION_FILE_TMPL}"
        NEWLINE_STYLE UNIX)

add_library(automate-media SHARED GraphicsFacade.cxx Version.cxx)
set_target_properties(automate-media PROPERTIES
    VERSION ${LIB_CODE_VERSION})

# choose which subdirectories to build the graphics and window libraries from
add_subdirectory(Vulkan)
add_subdirectory(SDLWindow)

target_link_libraries(automate-media PRIVATE graphics window)
target_include_directories(automate-media PUBLIC "${PROJECT_SOURCE_DIR}/media" "${PROJECT_SOURCE_DIR}/include")
