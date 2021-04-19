#include "GraphicsFacade.h"

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
        };

        void InitDeviceList();

        std::vector<GPUDevice> mDevices;
        int mSelectedDeviceIndex;
};
