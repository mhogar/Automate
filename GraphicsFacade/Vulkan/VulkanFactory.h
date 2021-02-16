#ifndef GF_VULKAN_FACTORY_H
#define GF_VULKAN_FACTORY_H

#include "GraphicsFacade/GraphicsFactory.h"

class VulkanFactory : public GraphicsFactory {
    public:        
        virtual std::shared_ptr<GraphicsWindow> CreateWindow();
};

#endif
