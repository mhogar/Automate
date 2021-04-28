#pragma once

#include <string>
#include <vector>

struct GPUDeviceInfo {
    std::string Name;
};

class GPUFacade {
    public:
        virtual ~GPUFacade() {}

        virtual void Init() {}

        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList() = 0;
        virtual void SelectGPU(int index) = 0;
        virtual int GetSelectedGPUIndex() = 0;
};
