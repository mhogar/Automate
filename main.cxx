#include "MediaFacade.h"
#include "UserInterface.h"
#include "Version.h"
#include <stdexcept>
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

    // init the media instance and catch any errors
    try {
        MediaFacade::Instance()->Init();
    }
    catch(const std::runtime_error& e) {
        std::cerr << "Error initializing media: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    // run the program
    {
        UserInterface* ui = UserInterface::CreateInstance();
        ui->MainLoop();
        delete ui;
    }
    MediaFacade::Dispose();

    return EXIT_SUCCESS;
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
