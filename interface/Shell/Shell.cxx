#include "Shell.h"
#include "Commands/BasicCommands.h"
#include "Commands/GPUCommand.h"
#include <sstream>

UserInterface* UserInterface::CreateInstance() {
    return new Shell(std::cin, std::cout);
}

Shell::Shell(std::istream& in, std::ostream& out) 
    : mIn(in), mOut(out)
{
    mCommands.insert({
        std::pair<std::string, Command*>("help", new HelpCommand(mOut, mCommands)),
        std::pair<std::string, Command*>("exit", new ExitCommand(mOut)),
        std::pair<std::string, Command*>("gpu", new GPUCommand(mIn, mOut)),
    });
}

Shell::~Shell() {
    for (auto& pair : mCommands) {
        delete pair.second;
    }
}

void Shell::MainLoop() {
    bool quit = false;
    while (!quit) {
        mOut << "> ";

        // get the entered line
        std::string line;
        std::getline(mIn, line);

        if (line.size() == 0) {
            continue;
        }

        //-- parse the tokens --
        std::stringstream lineStream(line);
        std::vector<std::string> args;

        std::string token;
        while(lineStream >> token) {
            args.push_back(token);
        }

        // lookup the command and execute it if it exists
        auto itr = mCommands.find(args[0]);
        if (itr != mCommands.end()) {
           quit = itr->second->Execute(args);
        }
        else {
            mOut << "Command \"" << args[0] << "\" not found. Use \"help\" for usage.\n";
        }
    }
}
