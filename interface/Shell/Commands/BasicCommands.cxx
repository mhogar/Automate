#include "BasicCommands.h"
#include "Version.h"

HelpCommand::HelpCommand(std::ostream& out, const std::map<std::string, Command*>& commandsRef)
    : Command(out, "print this usage"), mCommandsRef(commandsRef) {}

bool HelpCommand::Execute(const std::vector<std::string>& args) {
    mOut << "Usage:\n";

    for (auto& pair : mCommandsRef) {
        Indent() << pair.first << ": ";
        pair.second->PrintUsage();
    }

    return false;
}

//--------------------------------------------------------------------------------

ExitCommand::ExitCommand(std::ostream& out)
    : Command(out, "exit the shell") {}

bool ExitCommand::Execute(const std::vector<std::string>& args) {
    return true;
}
