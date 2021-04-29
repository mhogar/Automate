#include "GPUSelector.h"

bool GPUDeviceInfo::SupportsFeatures(uint8_t features) {
    return SupportFlags & features;
}

void GPUSelector::SelectGPU(int index) {
    mSelectedDeviceIndex = index;
}

int GPUSelector::GetSelectedGPUIndex() {
    return mSelectedDeviceIndex;
}
