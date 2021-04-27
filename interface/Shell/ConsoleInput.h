#pragma once

#include "Channel.h"
#include <iostream>
#include <string>
#include <thread>

class ConsoleInput {
    public:
        ConsoleInput(std::istream& in);
        ~ConsoleInput();

        bool HasInput();
        std::vector<std::string> GetInput();

    private:
        void PollInput(std::istream& in);

        Channel<std::string> mChannel;
        std::thread* mInputThread;
};
