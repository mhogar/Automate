#include "PreviewShell.h"
#include "GraphicsFacade.h"

PreviewShell::PreviewShell(ConsoleInput* consoleIn, std::ostream& out)
    : Shell(consoleIn, out)
{
    mWindow = GraphicsFacade::Instance()->CreateWindow(800, 600, "Automate Preview");
    mOut << "preview > ";
}

PreviewShell::~PreviewShell() {
    mWindow->Close();
    delete mWindow;
}

void PreviewShell::Update() {
    //TODO: Run window events on a separate thread?
    mWindow->PollEvents();
    if (mWindow->ShouldClose()) {
        mShouldExit = true;
        return;
    }

    if (HandleInput()) {
        mOut << "preview > ";
    }
}
