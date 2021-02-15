#ifndef GF_VULKAN_VULKAN_WINDOW_H
#define GF_VULKAN_VULKAN_WINDOW_H

#include "GraphicsFacade/GraphicsWindow.h"
#include "VulkanRenderer.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class VulkanWindow : public GraphicsWindow {
    public:
        VulkanWindow(VulkanRenderer* renderer);
        ~VulkanWindow();

        virtual void CreateWindow(int width, int height, const char* title);
        virtual void DestroyWindow();

        virtual bool ShouldClose();
        virtual void PollEvents();
    
    private:
        GLFWwindow* mWindow;
        VulkanRenderer* mRenderer;
};

#endif
