#pragma once

#include "GPUFacade.h"
#include "QueueFamilyIndices.h"
#include <vulkan/vulkan.h>

struct GPUDevice {
    GPUDeviceInfo Info;
    QueueFamilyIndices Indices;
    VkPhysicalDevice PhysicalDevice;
};

class VulkanGPUFacade : public GPUFacade {
    public:
        VulkanGPUFacade(VkInstance instance, GPUDevice& device);

        virtual void Init();

        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList();
        virtual void SelectGPU(int index);
        virtual int GetSelectedGPUIndex();

    private:
        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

        VkInstance mVKInstance;

        std::vector<GPUDevice> mDevices;
        int mSelectedDeviceIndex;
        GPUDevice& mDeviceRef;
};
