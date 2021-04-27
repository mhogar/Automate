#include "BaseShell.h"
#include "PreviewShell.h"
#include "GPUShell.h"

BaseShell::BaseShell(std::istream& in, std::ostream& out)
    : Shell(in, out)
{
    mCommands.insert({
        std::pair<std::string, Command>("preview",
            {
                "enter shell layer for creating and controlling the preview window", {},
                [this](const std::vector<std::string>& args) { HandlePreviewCommand(args); }
            }
        ),
        std::pair<std::string, Command>("gpu",
            {
                "enter shell layer for viewing and selecting available GPUs", {},
                [this](const std::vector<std::string>& args) { HandleGPUCommand(args); }
            }
        ),
    });
}


void BaseShell::Update() {
    mOut << "> ";
    HandleInput();
}

void BaseShell::HandlePreviewCommand(const std::vector<std::string>& args) {
    PreviewShell(mIn, mOut).RunShell();
}

void BaseShell::HandleGPUCommand(const std::vector<std::string>& args) {
    GPUShell(mIn, mOut).RunShell();
}
