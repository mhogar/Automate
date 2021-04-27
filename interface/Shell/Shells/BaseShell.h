#pragma once
#include "Shell.h"

class BaseShell : public Shell {
    public:
        BaseShell(std::istream& in, std::ostream& out);

        virtual void Update();

    private:
        void HandlePreviewCommand(const std::vector<std::string>& args);
        void HandleGPUCommand(const std::vector<std::string>& args);
};
