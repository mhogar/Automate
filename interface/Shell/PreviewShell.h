#pragma once

#include "Shell.h"

class PreviewShell : public Shell {
    public:
        PreviewShell(std::istream& in, std::ostream& out);

        virtual bool Update();
};
