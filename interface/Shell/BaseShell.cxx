#include "BaseShell.h"
#include "Commands/GPUCommand.h"

UserInterface* UserInterface::CreateInstance() {
    return new BaseShell(std::cin, std::cout);
}

BaseShell::BaseShell(std::istream& in, std::ostream& out)
    : Shell(in, out)
{
    mCommands.insert({
        std::pair<std::string, Command*>("gpu", new GPUCommand(mOut)),
    });
}

void BaseShell::MainLoop() {
    bool quit = false;

    while (!quit) {
        mOut << "> ";
        quit = HandleInput();
    }
}
