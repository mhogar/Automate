#include "VulkanFactory.h"
#include "VulkanWindow.h"

// Choose Vulkan as the implementation for the graphics
GraphicsFactory* GraphicsFactory::CreateGraphicsFactory() {
    return new VulkanFactory();
}

VulkanFactory::VulkanFactory() {
    mRenderer = std::unique_ptr<VulkanRenderer>(new VulkanRenderer());
}

std::shared_ptr<GraphicsWindow> VulkanFactory::CreateWindow() {
    return std::shared_ptr<GraphicsWindow>(new VulkanWindow(mRenderer.get()));
}

GraphicsRenderer* VulkanFactory::GetRenderer() {
    return mRenderer.get();
}
