#include "BaseShell.h"
#include "PreviewShell.h"
#include "GPUShell.h"

BaseShell::BaseShell(std::istream& in, std::ostream& out)
    : Shell(in, out)
{
    mCommands.insert({
        std::pair<std::string, Command>("preview",
            {
                "(shell) open the preview window", {},
                [this](const std::vector<std::string>& args) { HandlePreviewCommand(args); }
            }
        ),
        std::pair<std::string, Command>("gpu",
            {
                "(shell) view and select available GPUs", {},
                [this](const std::vector<std::string>& args) { HandleGPUCommand(args); }
            }
        ),
    });

    mOut << "> ";
}


void BaseShell::Update() {
    if (HandleInput()) {
        mOut << "> ";
    }
}

void BaseShell::HandlePreviewCommand(const std::vector<std::string>& args) {
    PreviewShell(mConsoleIn, mOut).RunShell();
}

void BaseShell::HandleGPUCommand(const std::vector<std::string>& args) {
    GPUShell(mConsoleIn, mOut).RunShell();
}
