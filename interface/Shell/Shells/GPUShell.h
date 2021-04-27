#pragma once

#include "Shell.h"
#include "GraphicsFacade.h"

class GPUShell : public Shell {
    public:
        GPUShell(ConsoleInput* consoleIn, std::ostream& out);

        virtual void Update();

    private:
        void HandleListCommand(const std::vector<std::string>& args);
        void HandleSelectCommand(const std::vector<std::string>& args);

        void PrintGPUList();

        std::vector<GPUDeviceInfo> mGPUInfos;
        int mSelectedGPUIndex;
};
