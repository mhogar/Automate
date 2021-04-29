#include "PreviewShell.h"
#include "MediaFacade.h"
#include <stdexcept>

PreviewShell::PreviewShell(std::istream& in, std::ostream& out)
    : Shell(in, out)
{
    if (!MediaFacade::Instance()->GetGPUSelector()->GetSeletedDeviceInfo().SupportsFeatures(FeatureSupportFlags::PREVIEW)) {
        throw std::runtime_error("preview not supported by selected GPU. Run \"gpu\" to view options");
    }

    mWindow = MediaFacade::Instance()->CreatePreviewWindow();

    mCommands.insert({
        std::pair<std::string, Command>("open",
            {
                "open the preview window", {},
                [this](const std::vector<std::string>& args) { HandleOpenCommand(args); }
            }
        ),
        std::pair<std::string, Command>("close",
            {
                "close the preview window", {},
                [this](const std::vector<std::string>& args) { HandleCloseCommand(args); }
            }
        ),
    });
}

PreviewShell::~PreviewShell() {
    delete mWindow;
}

void PreviewShell::Update() {
    mOut << "preview > ";
    HandleInput();
}

void PreviewShell::HandleOpenCommand(const std::vector<std::string>& args) {
    if (mWindow->IsOpen()) {
        Indent(1) << "the window is already open\n";
        return;
    }

    mWindow->Open();
}

void PreviewShell::HandleCloseCommand(const std::vector<std::string>& args) {
    if (!mWindow->IsOpen()) {
        Indent(1) << "the window is already closed\n";
        return;
    }

    mWindow->Close();
}
