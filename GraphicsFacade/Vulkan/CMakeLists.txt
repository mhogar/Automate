list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_package(GLFW REQUIRED)
find_package(Vulkan REQUIRED)

add_library(vulkan VulkanFactory.cxx VulkanWindow.cxx VulkanRenderer.cxx)

target_link_libraries(vulkan PRIVATE "${GLFW_LIBRARIES}" "${Vulkan_LIBRARIES}")
target_include_directories(vulkan PUBLIC "${PROJECT_SOURCE_DIR}" "${GLFW_INCLUDE_DIR}" "${Vulkan_INCLUDE_DIR}")
