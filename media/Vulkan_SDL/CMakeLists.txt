find_package(Vulkan REQUIRED)
find_package(SDL2 REQUIRED)

add_library(media VulkanSDLMediaFacade.cxx VulkanGPUSelector.cxx SDLPreviewWindow.cxx QueueFamilyIndices.cxx)

target_link_libraries(media PRIVATE "${Vulkan_LIBRARIES}" "${SDL2_LIBRARIES}")
target_include_directories(media PUBLIC "${PROJECT_SOURCE_DIR}/media" "${PROJECT_SOURCE_DIR}/include" "${Vulkan_INCLUDE_DIR}" "${SDL2_INCLUDE_DIR}")
