#pragma once

#include <string>
#include <vector>

struct GPUDeviceInfo {
    std::string Name;
    bool Recommended;
};

class GPUSelector {
    public:
        virtual ~GPUSelector() {}

        virtual void QueryDeviceList() = 0;

        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList() = 0;
        virtual void SelectGPU(int index) = 0;
        virtual int GetSelectedGPUIndex() = 0;
};
