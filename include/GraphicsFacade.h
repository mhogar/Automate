#pragma once

#include <string>
#include <vector>

struct GPUDeviceInfo {
    std::string Name;
};

class GraphicsFacade {
    public:
        virtual ~GraphicsFacade() {};

        virtual std::vector<GPUDeviceInfo> GetGPUDeviceList() = 0;
        virtual void SelectGPU(int index) = 0;
        virtual int GetSelectedGPUIndex() = 0;

        static GraphicsFacade* Instance();
        static void Dispose();

    private:
        static GraphicsFacade* CreateInstance();
        static GraphicsFacade* mInstance;
};
