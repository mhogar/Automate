#include "GraphicsFacade.h"
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
            std::cout << "Unknown argument. Run with --help for usage.\n";
        }

        return 0;
    }

    // init and run the program
    GraphicsFacade::Instance()->Init();
    {
        UserInterface* ui = UserInterface::CreateInstance();
        ui->MainLoop();
        delete ui;
    }
    GraphicsFacade::Dispose();
}

std::ostream& indent() {
    return std::cout << "  ";
}

void handleHelpCommand() {
    std::cout << "Usage: Runs the automate interface\n";
    std::cout << "Optional:\n";
    indent() << "--help: print this usage\n";
    indent() << "--version: print version info\n";
}

void printVersion(const char* name, const Version& version) {
    indent() << name << ": v" << version.CodeVersion << " (API v" << version.APIVersion << ")\n";
}

void handleVersionCommand() {
    std::cout << "Version:\n";
    printVersion("core", Version::Core());
    printVersion("interface", Version::Interface());
    printVersion("media", Version::Media());
}
