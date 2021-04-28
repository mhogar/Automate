#include "VulkanGPUFacade.h"
#include <stdexcept>

VulkanGPUFacade::VulkanGPUFacade(VkInstance instance, GPUDevice& device)
    : mVKInstance(instance), mDeviceRef(device) {}

void VulkanGPUFacade::Init() {
    //-- get all the graphics cards --
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(mVKInstance, &deviceCount, nullptr);

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(mVKInstance, &deviceCount, devices.data());

    // -- build the device structs and select a default --
    mDevices.clear();
    int defaultIndex = 0;

    for (int i = 0; i < deviceCount; i++) {
        const VkPhysicalDevice device = devices[i];

        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);

        mDevices.push_back({
            deviceProperties.deviceName,
            FindQueueFamilies(device),
            device,
        });

        // choose a discrete graphics card as the default if possible
        if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
            defaultIndex = i;
        }
    }

    if (mDevices.size() == 0) {
        throw std::runtime_error("no vulkan compatible GPUs found");
    }

    SelectGPU(defaultIndex);
}

std::vector<GPUDeviceInfo> VulkanGPUFacade::GetGPUDeviceList() {
    std::vector<GPUDeviceInfo> infos;
    infos.reserve(mDevices.size());

    for (GPUDevice& device : mDevices) {
        infos.push_back(device.Info);
    }

    return infos;
}

void VulkanGPUFacade::SelectGPU(int index) {
    mSelectedDeviceIndex = index;
    mDeviceRef = mDevices[index];
}

int VulkanGPUFacade::GetSelectedGPUIndex() {
    return mSelectedDeviceIndex;
}

QueueFamilyIndices VulkanGPUFacade::FindQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indices;

    //-- get all the queue families --
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    // find a queue familly for each required operation
    for (int i = 0; i < queueFamilyCount; i++) {
        const VkQueueFamilyProperties& queueFamily = queueFamilies[i];

        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.GraphicsFamily = i;
        }
    }

    return indices;
}
