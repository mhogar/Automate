#include "PreviewShell.h"
#include "GraphicsFacade.h"

PreviewShell::PreviewShell(std::istream& in, std::ostream& out)
    : Shell(in, out)
{
    mWindow = GraphicsFacade::Instance()->CreateWindow(800, 600, "Automate Preview");
}

PreviewShell::~PreviewShell() {
    mWindow->Close();
    delete mWindow;
}

bool PreviewShell::Update() {
    //TODO: Run window events on a separate thread?
    mWindow->PollEvents();
    if (mWindow->ShouldClose()) {
        return true;
    }

    mOut << "(preview) > ";
    return HandleInput();
}
