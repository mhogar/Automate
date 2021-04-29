#include "VulkanPreviewRenderer.h"
#include <vector>
#include <set>

VulkanPreviewRenderer::VulkanPreviewRenderer(VkInstance instance, VkSurfaceKHR surface, VkPhysicalDevice physicalDevice, QueueFamilyIndices& indices)
    : mVKInstance(instance), mSurface(surface), mPhysicalDevice(physicalDevice), mIndices(indices)
{
    CreateLogicalDevice();
}

VulkanPreviewRenderer::~VulkanPreviewRenderer() {
    vkDestroyDevice(mDevice, nullptr);
}

void VulkanPreviewRenderer::CreateLogicalDevice() {
    //-- create the create info for the all the unique queue families --
    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    std::set<uint32_t> uniqueQueueFamilies = {mIndices.GraphicsFamily.value(), mIndices.PresentFamily.value()};

    float queuePriority = 1.0f;
    for (uint32_t queueFamily : uniqueQueueFamilies) {
        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = queueFamily;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &queuePriority;
        queueCreateInfos.push_back(queueCreateInfo);
    }

    // specify device features
    VkPhysicalDeviceFeatures deviceFeatures{};

    //-- create the create info for the logical device --
    VkDeviceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

    createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
    createInfo.pQueueCreateInfos = queueCreateInfos.data();

    createInfo.pEnabledFeatures = &deviceFeatures;

    createInfo.enabledExtensionCount = 0;
    createInfo.enabledLayerCount = 0; // validation layers do not need to be respecified

    // create the logical device
    if (vkCreateDevice(mPhysicalDevice, &createInfo, nullptr, &mDevice) != VK_SUCCESS) {
        throw std::runtime_error("failed to create vulkan logical device");
    }

    // retrieve a handle for the queues
    vkGetDeviceQueue(mDevice, mIndices.GraphicsFamily.value(), 0, &mGraphicsQueue);
    vkGetDeviceQueue(mDevice, mIndices.PresentFamily.value(), 0, &mPresentQueue);

}
