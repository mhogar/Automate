#include "PreviewShell.h"

PreviewShell::PreviewShell(std::istream& in, std::ostream& out)
    : Shell(in, out) {}

bool PreviewShell::Update() {
    mOut << "preview > ";
    return HandleInput();
}
