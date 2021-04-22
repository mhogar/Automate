#pragma once

#include "Command.h"

class PreviewCommand : public Command {
    public:
        PreviewCommand(std::istream& in, std::ostream& out);
        virtual bool Execute(const std::vector<std::string>& args);

    private:
        std::istream& mIn;
};
