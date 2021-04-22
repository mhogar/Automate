#include "PreviewCommand.h"
#include "PreviewShell.h"

PreviewCommand::PreviewCommand(std::istream& in, std::ostream& out)
    : Command(out, "open the preview window"), mIn(in) {}

bool PreviewCommand::Execute(const std::vector<std::string>& args) {
    PreviewShell shell(mIn, mOut);
    while (!shell.Update());
    return false;
}
