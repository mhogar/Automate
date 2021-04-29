#include "VulkanSDLMediaFacade.h"
#include "SDLPreviewWindow.h"
#include <SDL2/SDL_vulkan.h>
#include <stdexcept>
#include <cstring>
#include <iostream>

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
    delete mGPUSelector;
    vkDestroySurfaceKHR(mVKInstance, mSurface, nullptr);
    vkDestroyInstance(mVKInstance, nullptr);

    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void VulkanSDLMediaFacade::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("failed to init SDL");
    }
    mWindow = SDL_CreateWindow("Automate", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_VULKAN | SDL_WINDOW_HIDDEN);

    CreateInstance();
    CreateSurface();

    mGPUSelector = new VulkanGPUSelector(mVKInstance, mSurface, mGPUDevice);
    mGPUSelector->QueryDeviceList();
}

GPUSelector* VulkanSDLMediaFacade::GetGPUSelector() {
    return mGPUSelector;
}

PreviewWindow* VulkanSDLMediaFacade::CreatePreviewWindow() {
    return new SDLPreviewWindow(mWindow);
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

    //-- get the required SDL extensions --
    uint sdlExtentionCount;
    SDL_Vulkan_GetInstanceExtensions(mWindow, &sdlExtentionCount, nullptr);

    std::vector<const char*> sdlExtentionNames;
    sdlExtentionNames.resize(sdlExtentionCount);

    SDL_Vulkan_GetInstanceExtensions(mWindow, &sdlExtentionCount, sdlExtentionNames.data());

    //-- tell Vulkan which global extensions and validation layers to use --
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    createInfo.enabledExtensionCount = sdlExtentionCount;
    createInfo.ppEnabledExtensionNames = sdlExtentionNames.data();

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

void VulkanSDLMediaFacade::CreateSurface() {
    if (SDL_Vulkan_CreateSurface(mWindow, mVKInstance, &mSurface) != SDL_TRUE) {
        throw std::runtime_error("failed to create vulkan window surface");
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
