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
                {
                    { "name", "print detailed usage including arguments for this command", false },
                },
                [this](const std::vector<std::string>& args) { HandleHelpCommand(args); }
            }
        ),
        std::pair<std::string, Command>("exit",
            {
                "exit the shell layer", {},
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

int Shell::Command::RequiredArgsCount() {
    int count = 0;
    for (const CommandArg& arg : Args) {
        if (arg.Required) {
            count++;
        }
    }

    return count;
}


std::ostream& Shell::Indent(int num) {
    for (int i = 0; i < num; i++) {
        mOut << "  ";
    }
    return mOut << "* ";
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
        if (args.size() > itr->second.RequiredArgsCount()) {
            itr->second.ExecuteFunc(args);
        }
        else {
            Indent(1) << "Too few args. Use \"help " << args[0] << "\" for usage.\n";
        }
    }
    else {
        Indent(1) << "Command \"" << args[0] << "\" not found. Use \"help\" for command list.\n";
    }
}

void Shell::PrintCommandUsage(const std::string& name, const Command& command, bool printArgs) {
    // print command with args and usage
    Indent(1) << name;
    if (printArgs) {
        for (const CommandArg& arg : command.Args) {
            mOut << " <" << arg.Name << ">";
        }
    }
    mOut << ": " << command.Usage << "\n";
    
    // print arg usage
    if (printArgs) {
        for (const CommandArg& arg : command.Args) {
            Indent(2) << arg.Name << " (" << (arg.Required ? "required" : "optional") << "): " << arg.Usage << "\n";
        }
    }
}

void Shell::HandleExitCommand(const std::vector<std::string>& args) {
    mShouldExit = true;
}

void Shell::HandleHelpCommand(const std::vector<std::string>& args) {
    if (args.size() > 1) {
        // lookup the command and print its usage if it exists
        auto itr = mCommands.find(args[1]);
        if (itr != mCommands.end()) {
            PrintCommandUsage(itr->first, itr->second, true);
        }
        else {
            Indent(1) << "Command \"" << args[1] << "\" not found.\n";
        }

        return;
    }

    // print usage for every command
    for (const auto& pair : mCommands) {
        PrintCommandUsage(pair.first, pair.second, false);
    }
}
