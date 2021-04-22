find_package(Vulkan REQUIRED)

add_library(graphics VulkanFacade.cxx)

target_link_libraries(graphics PRIVATE "${Vulkan_LIBRARIES}")
target_include_directories(graphics PUBLIC "${PROJECT_SOURCE_DIR}/media" "${PROJECT_SOURCE_DIR}/include" "${Vulkan_INCLUDE_DIR}")
