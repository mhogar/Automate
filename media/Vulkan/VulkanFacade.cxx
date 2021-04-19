#include "VulkanFacade.h"

GraphicsFacade* GraphicsFacade::CreateInstance() {
    return new VulkanFacade();
}

VulkanFacade::VulkanFacade() {
    mSelectedDeviceIndex = -1;

    InitDeviceList();
}

VulkanFacade::~VulkanFacade() {
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
    mSelectedDeviceIndex = index;
}

int VulkanFacade::GetSelectedGPUIndex() {
    return mSelectedDeviceIndex;
}

void VulkanFacade::InitDeviceList() {
    mSelectedDeviceIndex = 0;
    mDevices = {
        GPUDevice { GPUDeviceInfo { "GeForce RTX 2060" } },
        GPUDevice { GPUDeviceInfo { "Some Other GPU" } },
    };
}
