#pragma once

#include "Commands/Command.h"
#include <map>

class Shell {
    public:
        Shell(std::istream& in, std::ostream& out);
        virtual ~Shell();

    protected:
        bool HandleInput();

        std::istream& mIn;
        std::ostream& mOut;

        std::map<std::string, Command*> mCommands;
};
