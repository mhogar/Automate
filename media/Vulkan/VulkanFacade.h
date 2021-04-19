#include "GraphicsFacade.h"
#include <vulkan/vulkan.h>

class VulkanFacade : public GraphicsFacade {
    public:
        VulkanFacade();
        ~VulkanFacade();

        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList();
        virtual void SelectGPU(int index);
        virtual int GetSelectedGPUIndex();

    private:
        struct GPUDevice {
            GPUDeviceInfo Info;
            VkPhysicalDevice PhysicalDevice;
        };

        void CreateInstance();
        bool CheckValidationLayerSupport();

        void InitDeviceList();
        //void CreateLogicalDevice();

        VkInstance mVKInstance;
        //VkDevice mDevice;
        //VkQueue mGraphicsQueue;

        std::vector<GPUDevice> mDevices;
        int mSelectedDeviceIndex;
};
