#include "VulkanFacade.h"
#include "SDLWindow/SDLWindow.h"
#include <stdexcept>
#include <cstring>

const std::vector<const char*> gValidationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool gEnableValidationLayers = false;
#else
    const bool gEnableValidationLayers = true;
#endif

GraphicsFacade* GraphicsFacade::CreateInstance() {
    return new VulkanFacade();
}

VulkanFacade::~VulkanFacade() {
    //vkDestroyDevice(mDevice, nullptr);
    vkDestroyInstance(mVKInstance, nullptr);
}

void VulkanFacade::Init() {
    mSelectedDeviceIndex = -1;

    CreateInstance();
    InitDeviceList();
}

Window* VulkanFacade::CreateWindow(int width, int height, const char* title) {
    return new SDLWindow(width, height, title);
}

std::vector<GPUDeviceInfo> VulkanFacade::GetGPUDeviceList() {
    std::vector<GPUDeviceInfo> infos;
    infos.reserve(mDevices.size());

    for (GPUDevice& device : mDevices) {
        infos.push_back(device.Info);
    }

    return infos;
}

void VulkanFacade::SelectGPU(int index) {
    if (index == mSelectedDeviceIndex) {
        return;
    }

    mSelectedDeviceIndex = index;
}

int VulkanFacade::GetSelectedGPUIndex() {
    return mSelectedDeviceIndex;
}

void VulkanFacade::CreateInstance() {
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

    //-- tell Vulkan which global extensions and validation layers to use --
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

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

bool VulkanFacade::CheckValidationLayerSupport() {
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

void VulkanFacade::InitDeviceList() {
    //-- get all the graphics cards --
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(mVKInstance, &deviceCount, nullptr);

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(mVKInstance, &deviceCount, devices.data());

    // create an info struct for each device
    mDevices.clear();
    for (auto& device : devices) {
        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);

        mDevices.push_back({
            deviceProperties.deviceName,
            device,
        });
    }
}
