#pragma once

#include <string>
#include <vector>

enum FeatureSupportFlags {
    PREVIEW = 0x1,
};

struct GPUDeviceInfo {
    std::string Name;
    bool Recommended;
    uint8_t SupportFlags;

    bool SupportsFeatures(uint8_t features);
};

class GPUSelector {
    public:
        virtual ~GPUSelector() {}

        virtual void SelectGPU(int index);
        virtual int GetSelectedGPUIndex();

        virtual void QueryDeviceList() = 0;

        virtual GPUDeviceInfo GetSeletedDeviceInfo() = 0;
        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList() = 0;
        
    protected:
        int mSelectedDeviceIndex;
};
