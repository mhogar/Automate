#ifndef GF_VULKAN_RENDERER_H
#define GF_VULKAN_RENDERER_H

#include "GraphicsFacade/GraphicsRenderer.h"
#include <vulkan/vulkan.h>

class VulkanRenderer : public GraphicsRenderer {
    public:
        VulkanRenderer();
        ~VulkanRenderer();

        void NotifyFrameBufferResized();

    private:
        bool mFrameBufferResized;
        VkInstance mVKInstance;

        void CreateInstance();

        bool CheckValidationLayerSupport();
};

#endif
