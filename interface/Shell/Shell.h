#pragma once

#include "UserInterface.h"
#include <iostream>

class Shell: public UserInterface {
    public:
        Shell(std::istream& in, std::ostream& out);
        virtual void MainLoop();

    private:
        std::istream& mIn;
        std::ostream& mOut;
};
