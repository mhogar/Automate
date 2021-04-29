#include "MediaFacade.h"
#include "VulkanGPUSelector.h"
#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <optional>

class VulkanSDLMediaFacade : public MediaFacade {
    public:
        ~VulkanSDLMediaFacade();

        void Init();

        virtual GPUSelector* GetGPUFacade();
        virtual PreviewWindow* CreatePreviewWindow();

    private:
        void CreateInstance();
        //void CreateSurface();

        bool CheckValidationLayerSupport();

        VulkanGPUSelector* mGPUSelector;

        VkInstance mVKInstance;

        SDL_Window* mWindow;
        VkSurfaceKHR mSurface;

        GPUDevice mGPUDevice;
};
