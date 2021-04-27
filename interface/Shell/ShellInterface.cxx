#include "ShellInterface.h"
#include "Shells/BaseShell.h"

UserInterface* UserInterface::CreateInstance() {
    return new ShellInterface(std::cin, std::cout);
}

ShellInterface::ShellInterface(std::istream& in, std::ostream& out)
    : mIn(in), mOut(out) {}

void ShellInterface::MainLoop() {
    BaseShell(mIn, mOut).RunShell();
}
