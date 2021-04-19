#pragma once

#include "Command.h"

class GPUCommand : public Command {
    public:
        GPUCommand(std::istream& in, std::ostream& out);
        virtual bool Execute(const std::vector<std::string>& args);
    
    private:
        std::istream& mIn;
};
