#ifndef GF_VULKAN_RENDERER_H
#define GF_VULKAN_RENDERER_H

#include "GraphicsFacade/GraphicsRenderer.h"
#include <vulkan/vulkan.h>
#include <optional>

class VulkanRenderer : public GraphicsRenderer {
    public:
        VulkanRenderer();
        ~VulkanRenderer();

        void NotifyFrameBufferResized();

    private:
        struct QueueFamilyIndices {
            std::optional<uint32_t> mGraphicsFamily;
            bool IsComplete();
        };

        bool mFrameBufferResized;

        VkInstance mVKInstance;
        VkPhysicalDevice mPhysicalDevice;
        VkDevice mDevice;
        VkQueue mGraphicsQueue;

        void CreateInstance();
        void PickPhysicalDevice();
        void CreateLogicalDevice();

        bool CheckValidationLayerSupport();
        int RateDeviceSuitability(VkPhysicalDevice device);
        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
};

#endif
