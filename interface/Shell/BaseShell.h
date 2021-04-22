#pragma once

#include "UserInterface.h"
#include "Shell.h"

class BaseShell : public Shell, public UserInterface  {
    public:
        BaseShell(std::istream& in, std::ostream& out);

        virtual void MainLoop();
};
