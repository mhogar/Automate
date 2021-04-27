#pragma once

#include "ConsoleInput.h"
#include <map>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Shell {
    public:
        Shell(std::istream& in, std::ostream& out);
        virtual ~Shell();

        void RunShell();

    protected:
        struct CommandArg {
            std::string Name;
            std::string Usage;
            bool Required;
        };

        struct Command {
            std::string Usage;
            std::vector<CommandArg> Args;
            std::function<void(const std::vector<std::string>&)> ExecuteFunc;

            int RequiredArgsCount();
        };

        Shell(ConsoleInput* consoleIn, std::ostream& out);

        virtual void Update() = 0;

        std::ostream& Indent(int num);
        bool HandleInput();

        ConsoleInput* mConsoleIn;
        std::ostream& mOut;

        std::map<std::string, Command> mCommands;
        bool mShouldExit;

    private:
        void PrintCommandUsage(const std::string& name, const Command& command, bool printArgs);

        void HandleExitCommand(const std::vector<std::string>& args);
        void HandleHelpCommand(const std::vector<std::string>& args);
};
