#include "VulkanRenderer.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <cstring>

const std::vector<const char*> gValidationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool gEnableValidationLayers = false;
#else
    const bool gEnableValidationLayers = true;
#endif

VulkanRenderer::VulkanRenderer() {
    mFrameBufferResized = false;

    CreateInstance();
}

VulkanRenderer::~VulkanRenderer() {
    vkDestroyInstance(mVKInstance, nullptr);
}

void VulkanRenderer::NotifyFrameBufferResized() {
    mFrameBufferResized = true;
}

void VulkanRenderer::CreateInstance() {
    if (gEnableValidationLayers && !CheckValidationLayerSupport()) {
        throw std::runtime_error("validation layers requested, but not available");
    }

    //-- provide information about the app to enable possible optimizations --
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Automate";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    //-- tell Vulkan which gloabl extensions and validation layers to use --
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    if (gEnableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(gValidationLayers.size());
        createInfo.ppEnabledLayerNames = gValidationLayers.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    //-- create the instance --
    if (vkCreateInstance(&createInfo, nullptr, &mVKInstance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create vk instance");
    }
}

bool VulkanRenderer::CheckValidationLayerSupport() {
    //-- get the available validation layers --
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    //-- verify all required validation layers are available --
    for (const char* layerName : gValidationLayers) {
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers) {
            if (strcmp(layerName, layerProperties.layerName) == 0) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            return false;
        }
    }

    return true;
}
