#pragma once

#include "UserInterface.h"
#include "Commands/Command.h"
#include <map>

class Shell: public UserInterface {
    public:
        Shell(std::istream& in, std::ostream& out);
        ~Shell();

        virtual void MainLoop();

    private:
        std::istream& mIn;
        std::ostream& mOut;

        std::map<std::string, Command*> mCommands;
};
