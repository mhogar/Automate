#include "UserInterface.h"
#include "Version.h"
#include <string>
#include <iostream>

void handleHelpCommand();
void handleVersionCommand();

int main(int argc, const char** argv) {
    // handle args if present
    if (argc > 1) {
        std::string arg(argv[1]);
        if (arg == "-h" || arg == "--help") {
            handleHelpCommand();
        }
        else if (arg == "-v" || arg == "--version") {
            handleVersionCommand();
        }
        else {
            std::cout << "Unknown argument. Run with --help for usage." << std::endl;
        }

        return 0;
    }

    // create and run the interface
    UserInterface* ui = UserInterface::CreateInstance();
    ui->MainLoop();
    delete ui;
}

std::ostream& indent() {
    return std::cout << "  ";
}

void handleHelpCommand() {
    std::cout << "Usage: Runs the automate interface" << std::endl;
    std::cout << "Optional:" << std::endl;
    indent() << "--help: print this usage" << std::endl;
    indent() << "--version: print version info" << std::endl;
}

void printVersion(const char* name, const Version& version) {
    indent() << name << ": v" << version.CodeVersion << " (API v" << version.APIVersion << ")" << std::endl;
}

void handleVersionCommand() {
    std::cout << "Version:" << std::endl;
    printVersion("core", Version::Core());
    printVersion("interface", Version::Interface());
}
