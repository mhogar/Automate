#pragma once

#include "GPUSelector.h"
#include "QueueFamilyIndices.h"
#include <vulkan/vulkan.h>

struct GPUDevice {
    GPUDeviceInfo Info;
    QueueFamilyIndices Indices;
    VkPhysicalDevice PhysicalDevice;
};

class VulkanGPUSelector : public GPUSelector {
    public:
        VulkanGPUSelector(VkInstance instance, GPUDevice& device);

        virtual void QueryDeviceList();

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
