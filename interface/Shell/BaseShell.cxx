#include "BaseShell.h"
#include "Commands/GPUCommand.h"
#include "Commands/PreviewCommand.h"

UserInterface* UserInterface::CreateInstance() {
    return new BaseShell(std::cin, std::cout);
}

BaseShell::BaseShell(std::istream& in, std::ostream& out)
    : Shell(in, out)
{
    mCommands.insert({
        std::pair<std::string, Command*>("gpu", new GPUCommand(mOut)),
        std::pair<std::string, Command*>("preview", new PreviewCommand(mIn, mOut)),
    });
}

bool BaseShell::Update() {
    mOut << "> ";
    return HandleInput();
}

void BaseShell::MainLoop() {
    while (!Update());
}
