#pragma once

#include "Shell.h"
#include "Window.h"

class PreviewShell : public Shell {
    public:
        PreviewShell(std::istream& in, std::ostream& out);
        ~PreviewShell();

        virtual void Update();
    
    private:
        Window *mWindow;
};
