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

        virtual void QueryDeviceList();

        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList();
        virtual void SelectGPU(int index);
        virtual int GetSelectedGPUIndex();

    private:
        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
        int RateDevice(const VkPhysicalDeviceProperties& deviceProperties, const QueueFamilyIndices& indices);

        VkInstance mVKInstance;
        VkSurfaceKHR mSurface;

        std::vector<GPUDevice> mDevices;
        int mSelectedDeviceIndex;
        GPUDevice& mDeviceRef;
};
