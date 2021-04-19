#include "GPUCommand.h"
#include "GraphicsFacade.h"

GPUCommand::GPUCommand(std::istream& in, std::ostream& out)
    : Command(out, "view and select a gpu for rendering"), mIn(in) {}

bool GPUCommand::Execute(const std::vector<std::string>& args) {
    // get gpu list and display to user
    std::vector<GPUDeviceInfo> infos = GraphicsFacade::Instance()->GetGPUDeviceList();
    int selectedIndex = GraphicsFacade::Instance()->GetSelectedGPUIndex();

    for (int i = 0; i < infos.size(); i++) {
        Indent() << i << ": " << infos[i].Name << " (compatibility list)";
        mOut << (i == selectedIndex ? " <- selected\n" : "\n");
    }

    //-- get index from user --
    int index = -1;
    bool error = false;

    do {
        mOut << "enter an index (<0 to cancel): ";
        error = !(mIn >> index);

        mIn.clear();
        mIn.ignore(1000, '\n');

        if (!error && index > 1) {
            mOut << "invalid index\n";
            error = true;
        }
    } while (error);

    // handle input
    if (index < 0) {
        mOut << "canceled\n";
    }
    else {
        mOut << "GPU " << index << " selected\n";
        GraphicsFacade::Instance()->SelectGPU(index);
    }

    return false;
}
