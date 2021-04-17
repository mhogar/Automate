#pragma once

#include <iostream>
#include <vector>
#include <string>

class Command {
    public:
        Command(std::ostream& out, std::string usage);
        virtual ~Command() {}

        void PrintUsage();
        virtual bool Execute(const std::vector<std::string>& args) = 0;

    protected:
        std::ostream& mOut;
        std::string mUsage;
};
