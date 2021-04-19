#include "Command.h"

Command::Command(std::ostream& out, std::string usage)
    : mOut(out)
{
    mUsage = usage;
}

void Command::PrintUsage() {
    mOut << mUsage << "\n";
}

std::ostream& Command::Indent() {
    return mOut << "  ";
}
