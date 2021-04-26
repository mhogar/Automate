#include "Shell.h"
#include <sstream>

void Foo(const std::vector<std::string>& args) {}

Shell::Shell(std::istream& in, std::ostream& out) 
    : mIn(in), mOut(out)
{
    mShouldExit = false;

    mCommands.insert({
        std::pair<std::string, Command>("help",
            {
                "print this usage", 
                [this](const std::vector<std::string>& args) { HandleHelpCommand(args); }
            }
        ),
        std::pair<std::string, Command>("exit",
            {
                "exit the shell layer", 
                [this](const std::vector<std::string>& args) { HandleExitCommand(args); }
            }
        ),
    });
}

void Shell::RunShell() {
    while (!mShouldExit) {
        Update();
    }
}

std::ostream& Shell::Indent() {
    return mOut << "  ";
}

void Shell::HandleInput() {
    // get the entered line
    std::string line;
    std::getline(mIn, line);

    if (line.size() == 0) {
        return;
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
        itr->second.ExecuteFunc(args);
    }
    else {
        mOut << "Command \"" << args[0] << "\" not found. Use \"help\" for usage.\n";
    }
}

void Shell::HandleExitCommand(const std::vector<std::string>& args) {
    mShouldExit = true;
}

void Shell::HandleHelpCommand(const std::vector<std::string>& args) {
    mOut << "Usage:\n";

    for (auto& pair : mCommands) {
        Indent() << pair.first << ": " << pair.second.Usage << "\n";
    }
}
