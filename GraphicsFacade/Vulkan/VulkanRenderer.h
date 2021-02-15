#ifndef GF_VULKAN_RENDERER_H
#define GF_VULKAN_RENDERER_H

#include "GraphicsFacade/GraphicsRenderer.h"

class VulkanRenderer : public GraphicsRenderer {
    public:
        VulkanRenderer();
        void NotifyFrameBufferResized();

    private:
        bool mFrameBufferResized;
};

#endif
