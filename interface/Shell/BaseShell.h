#pragma once

#include "UserInterface.h"
#include "Shell.h"

class BaseShell : public Shell, public UserInterface  {
    public:
        BaseShell(std::istream& in, std::ostream& out);

        virtual void MainLoop();
        virtual void Update();

    private:
        void HandlePreviewCommand(const std::vector<std::string>& args);
        void HandleGPUCommand(const std::vector<std::string>& args);
};
