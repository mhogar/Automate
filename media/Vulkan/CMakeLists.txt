add_library(graphics VulkanFacade.cxx)
target_include_directories(graphics PUBLIC "${PROJECT_SOURCE_DIR}/media/Vulkan" "${PROJECT_SOURCE_DIR}/include")
