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
        VulkanGPUSelector(VkInstance instance, VkSurfaceKHR surface, GPUDevice& device);

        virtual void SelectGPU(int index);

        virtual void QueryDeviceList();

        virtual GPUDeviceInfo GetSeletedDeviceInfo();
        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList();

    private:
        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
        int RateDevice(const GPUDevice& device, const VkPhysicalDeviceProperties& deviceProperties);

        VkInstance mVKInstance;
        VkSurfaceKHR mSurface;

        std::vector<GPUDevice> mDevices;
        GPUDevice& mDeviceRef;
};
