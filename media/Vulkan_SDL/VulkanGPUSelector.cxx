#include "VulkanGPUSelector.h"
#include <stdexcept>

VulkanGPUSelector::VulkanGPUSelector(VkInstance instance, VkSurfaceKHR surface, GPUDevice& device)
    : mVKInstance(instance), mSurface(surface), mDeviceRef(device) {}

void VulkanGPUSelector::SelectGPU(int index) {
    GPUSelector::SelectGPU(index);
    mDeviceRef = mDevices[index];
}

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

        // -- get the queue indices and set support flags based on availble queues --
        QueueFamilyIndices indices = FindQueueFamilies(device);
        uint8_t supportFlags = 0;

        if (indices.GraphicsFamily.has_value() && indices.PresentFamily.has_value()) {
            supportFlags |= FeatureSupportFlags::PREVIEW;
        }

        // -- get device properties and create device struct --
        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);

        mDevices.push_back({
            { deviceProperties.deviceName, false, supportFlags },
            indices,
            device,
        });

        // choose default with highest score
        int score = RateDevice(mDevices[i], deviceProperties);
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

GPUDeviceInfo VulkanGPUSelector::GetSeletedDeviceInfo() {
    return mDevices[mSelectedDeviceIndex].Info;
}

std::vector<GPUDeviceInfo> VulkanGPUSelector::GetGPUDeviceList() {
    std::vector<GPUDeviceInfo> infos;
    infos.reserve(mDevices.size());

    for (GPUDevice& device : mDevices) {
        infos.push_back(device.Info);
    }

    return infos;
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

int VulkanGPUSelector::RateDevice(const GPUDevice& device, const VkPhysicalDeviceProperties& deviceProperties) {
    int score = 0;

    // TODO: prefer gpu that supports the most features

    // prefer a discrete graphics card
    if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
        score += 1000;
    }

    // prefer that graphics and presentation share a queue family
    if (device.Indices.GraphicsFamily == device.Indices.PresentFamily) {
        score += 100;
    }

    return score;
}
