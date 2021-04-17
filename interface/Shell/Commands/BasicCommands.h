#pragma once

#include "Command.h"
#include <map>

class HelpCommand : public Command {
    public:
        HelpCommand(std::ostream& out, const std::map<std::string, Command*>& commandsRef);
        virtual bool Execute(const std::vector<std::string>& args);

    private:
        const std::map<std::string, Command*>& mCommandsRef;
};

//--------------------------------------------------------------------------------

class ExitCommand : public Command {
    public:
        ExitCommand(std::ostream& out);
        virtual bool Execute(const std::vector<std::string>& args);
};
