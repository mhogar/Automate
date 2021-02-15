add_library(graphics GraphicsFactory.cxx)

add_subdirectory(Vulkan)

target_link_libraries(graphics PRIVATE vulkan)
target_include_directories(graphics PUBLIC "${PROJECT_SOURCE_DIR}")
