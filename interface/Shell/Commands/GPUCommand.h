#pragma once

#include "Commands/Command.h"

class GPUCommand : public Command {
    public:
        GPUCommand(std::ostream& out);
        virtual bool Execute(const std::vector<std::string>& args);
};
