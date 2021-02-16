#include "VulkanFactory.h"
#include "VulkanWindow.h"

// Choose Vulkan as the implementation for the graphics
GraphicsFactory* GraphicsFactory::CreateGraphicsFactory() {
    return new VulkanFactory();
}

std::shared_ptr<GraphicsWindow> VulkanFactory::CreateWindow() {
    return std::shared_ptr<GraphicsWindow>(new VulkanWindow());
}
