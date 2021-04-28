#include "MediaFacade.h"
#include "VulkanGPUFacade.h"
#include <vulkan/vulkan.h>
#include <optional>

class VulkanSDLMediaFacade : public MediaFacade {
    public:
        ~VulkanSDLMediaFacade();

        void Init();

        virtual GPUFacade* GetGPUFacade();
        virtual PreviewWindow* CreatePreviewWindow();

    private:
        void CreateInstance();
        bool CheckValidationLayerSupport();

        VulkanGPUFacade* mGPUFacade;

        VkInstance mVKInstance;
        GPUDevice mGPUDevice;
};
