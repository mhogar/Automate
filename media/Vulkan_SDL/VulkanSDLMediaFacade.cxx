#include "VulkanSDLMediaFacade.h"
#include "SDLWindow.h"
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

MediaFacade* MediaFacade::CreateInstance() {
    return new VulkanSDLMediaFacade();
}

VulkanSDLMediaFacade::~VulkanSDLMediaFacade() {
    delete mGPUFacade;
    vkDestroyInstance(mVKInstance, nullptr);
    SDL_Quit();
}

void VulkanSDLMediaFacade::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("failed to init SDL");
    }

    CreateInstance();

    mGPUFacade = new VulkanGPUFacade(mVKInstance, mGPUDevice);
    mGPUFacade->Init();
}

GPUFacade* VulkanSDLMediaFacade::GetGPUFacade() {
    return mGPUFacade;
}

PreviewWindow* VulkanSDLMediaFacade::CreatePreviewWindow() {
    return new SDLWindow();
}

void VulkanSDLMediaFacade::CreateInstance() {
    if (gEnableValidationLayers && !CheckValidationLayerSupport()) {
        throw std::runtime_error("vulkan validation layers requested, but not available");
    }

    //-- provide information about the app to enable possible optimizations --
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Automate";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_1;

    // choose the required extensions
    const std::array<const char*, 1> extensionNames = {
        VK_KHR_SURFACE_EXTENSION_NAME,
    };

    //-- tell Vulkan which global extensions and validation layers to use --
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    createInfo.enabledExtensionCount = extensionNames.size();
    createInfo.ppEnabledExtensionNames = extensionNames.data();

    if (gEnableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(gValidationLayers.size());
        createInfo.ppEnabledLayerNames = gValidationLayers.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    // create the instance
    if (vkCreateInstance(&createInfo, nullptr, &mVKInstance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create the vulkan instance");
    }
}

bool VulkanSDLMediaFacade::CheckValidationLayerSupport() {
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
