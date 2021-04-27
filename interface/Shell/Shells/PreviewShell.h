#pragma once

#include "Shell.h"
#include "PreviewWindow.h"

class PreviewShell : public Shell {
    public:
        PreviewShell(std::istream& in, std::ostream& out);
        ~PreviewShell();

        virtual void Update();
    
    private:
        void HandleOpenCommand(const std::vector<std::string>& args);
        void HandleCloseCommand(const std::vector<std::string>& args);

        PreviewWindow* mWindow;

        static const int DEFAULT_WIDTH;
        static const int DEFAULT_HEIGHT;
        static const char* TITLE;
};
