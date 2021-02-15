#ifndef GF_VULKAN_FACTORY_H
#define GF_VULKAN_FACTORY_H

#include "GraphicsFacade/GraphicsFactory.h"
#include "VulkanRenderer.h"
#include <memory>

class VulkanFactory : public GraphicsFactory {
    public:
        VulkanFactory();
        
        virtual std::shared_ptr<GraphicsWindow> CreateWindow();
        virtual GraphicsRenderer* GetRenderer();

    private:
        std::unique_ptr<VulkanRenderer> mRenderer;
};

#endif
