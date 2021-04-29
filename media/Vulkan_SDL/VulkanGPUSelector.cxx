#include "VulkanGPUSelector.h"
#include <stdexcept>

VulkanGPUSelector::VulkanGPUSelector(VkInstance instance, VkSurfaceKHR surface, GPUDevice& device)
    : mVKInstance(instance), mSurface(surface), mDeviceRef(device) {}

void VulkanGPUSelector::QueryDeviceList() {
    //-- get all the graphics cards --
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(mVKInstance, &deviceCount, nullptr);

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(mVKInstance, &deviceCount, devices.data());

    mDevices.clear();
    mDevices.reserve(deviceCount);

    int defaultIndex = 0;
    int highestScore = 0;

    // build device structs
    for (int i = 0; i < deviceCount; i++) {
        const VkPhysicalDevice device = devices[i];

        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);

        QueueFamilyIndices indices = FindQueueFamilies(device);

        mDevices.push_back({
            { deviceProperties.deviceName, false },
            indices,
            device,
        });

        // choose default with highest score
        int score = RateDevice(deviceProperties, indices);
        if (score > highestScore) {
            highestScore = score;
            defaultIndex = 0;
        }
    }

    if (mDevices.size() == 0) {
        throw std::runtime_error("no vulkan compatible GPUs found");
    }

    mDevices[defaultIndex].Info.Recommended = true;
    SelectGPU(defaultIndex);
}

std::vector<GPUDeviceInfo> VulkanGPUSelector::GetGPUDeviceList() {
    std::vector<GPUDeviceInfo> infos;
    infos.reserve(mDevices.size());

    for (GPUDevice& device : mDevices) {
        infos.push_back(device.Info);
    }

    return infos;
}

void VulkanGPUSelector::SelectGPU(int index) {
    mSelectedDeviceIndex = index;
    mDeviceRef = mDevices[index];
}

int VulkanGPUSelector::GetSelectedGPUIndex() {
    return mSelectedDeviceIndex;
}

QueueFamilyIndices VulkanGPUSelector::FindQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indices;

    //-- get all the queue families --
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    // find a queue familly for each required operation
    for (int i = 0; i < queueFamilyCount; i++) {
        const VkQueueFamilyProperties& queueFamily = queueFamilies[i];

        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, mSurface, &presentSupport);

        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.GraphicsFamily = i;
        }

        if (presentSupport) {
            indices.PresentFamily = i;
        }

        if (indices.IsComplete()) {
            break;
        }
    }

    return indices;
}

int VulkanGPUSelector::RateDevice(const VkPhysicalDeviceProperties& deviceProperties, const QueueFamilyIndices& indices) {
    int score = 0;

    // prefer a discrete graphics card
    if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
        score += 1000;
    }

    // prefer that graphics and presentation share a queue family
    if (indices.GraphicsFamily == indices.PresentFamily) {
        score += 100;
    }

    return score;
}
