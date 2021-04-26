#pragma once

#include <map>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Shell {
    public:
        Shell(std::istream& in, std::ostream& out);
        virtual ~Shell() {}

        void RunShell();

    protected:
        struct Command {
            std::string Usage;
            std::function<void(const std::vector<std::string>&)> ExecuteFunc;
        };

        virtual void Update() = 0;

        std::ostream& Indent();
        void HandleInput();

        std::istream& mIn;
        std::ostream& mOut;

        std::map<std::string, Command> mCommands;
        bool mShouldExit;

    private:
        void HandleExitCommand(const std::vector<std::string>& args);
        void HandleHelpCommand(const std::vector<std::string>& args);
};
