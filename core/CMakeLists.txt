add_library(core Animation.cxx Version.cxx)

add_subdirectory(Animators)
add_subdirectory(Actors)
add_subdirectory(Actions)
add_subdirectory(Renderers)

target_link_libraries(core PRIVATE animators actors actions renderers)
target_include_directories(core PUBLIC "${PROJECT_SOURCE_DIR}/core" "${PROJECT_SOURCE_DIR}/include")
