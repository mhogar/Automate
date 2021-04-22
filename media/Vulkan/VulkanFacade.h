#include "GraphicsFacade.h"
#include <vulkan/vulkan.h>

class VulkanFacade : public GraphicsFacade {
    public:
        ~VulkanFacade();

        void Init();
        Window* CreateWindow(int width, int height, const char* title);

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
