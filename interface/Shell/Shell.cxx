#include "Shell.h"
#include "Versions.h"
#include <string>

UserInterface* UserInterface::CreateInstance() {
    return new Shell(std::cin, std::cout);
}

Shell::Shell(std::istream& in, std::ostream& out) 
    : mIn(in), mOut(out) {}

void Shell::MainLoop() {
    mOut << "automate shell interface " << AUTOMATE_SHELL_VERSION << std::endl;

    while (true) {
        std::string input;

        mOut << "> ";
        std::getline(mIn, input);

        if (input == "exit") {
            break;
        }

        mOut << "echo: " << input << std::endl;
    }
}
