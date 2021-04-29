#pragma once

#include "QueueFamilyIndices.h"
#include <vulkan/vulkan.h>

class VulkanPreviewRenderer {
    public:
        VulkanPreviewRenderer(VkInstance instance, VkSurfaceKHR surface, VkPhysicalDevice physicalDevice, QueueFamilyIndices& indices);
        ~VulkanPreviewRenderer();

    private:
        void CreateLogicalDevice();

        VkInstance mVKInstance;
        VkSurfaceKHR mSurface;
        VkPhysicalDevice mPhysicalDevice;
        QueueFamilyIndices mIndices;

        VkDevice mDevice;
        VkQueue mGraphicsQueue;
        VkQueue mPresentQueue;
};
