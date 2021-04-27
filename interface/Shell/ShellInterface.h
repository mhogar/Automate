#pragma once

#include "UserInterface.h"
#include <iostream>

class ShellInterface : public UserInterface {
    public:
        ShellInterface(std::istream& in, std::ostream& out);

        virtual void MainLoop();

    private:
        std::istream& mIn;
        std::ostream& mOut;
};
