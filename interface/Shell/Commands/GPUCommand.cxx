#include "GPUCommand.h"
#include "GraphicsFacade.h"

GPUCommand::GPUCommand(std::ostream& out)
    : Command(out, "view and select a gpu for rendering") {}

bool GPUCommand::Execute(const std::vector<std::string>& args) {
    // get gpu list and display to user
    std::vector<GPUDeviceInfo> infos = GraphicsFacade::Instance()->GetGPUDeviceList();

    //-- parse new index from args --
    int newIndex = -1;
    bool error = false;

    if (args.size() >= 2) {
        try {
            newIndex = std::stoi(args[1]);
        }
        catch (std::invalid_argument& e) {}

        if (newIndex < 0 || newIndex >= infos.size()) {
            error = true;
        }
    }

    // get the selected index if a new index wasn't provided
    int selectedIndex = newIndex;
    if (selectedIndex < 0 || error) {
        selectedIndex = GraphicsFacade::Instance()->GetSelectedGPUIndex();
    }

    // display the GPU list
    for (int i = 0; i < infos.size(); i++) {
        Indent() << i << ": " << infos[i].Name << " (compatibility list)";
        mOut << (i == selectedIndex ? " <- selected\n" : "\n");
    }

    // display appropriate message
    if (error) {
        mOut << "Invalid index\n";
    }
    else if (newIndex >= 0) {
        mOut << "GPU " << newIndex << " selected\n";
        GraphicsFacade::Instance()->SelectGPU(newIndex);
    }
    else {
        mOut << "Run `gpu <index>` to select another GPU\n";
    }

    return false;
}
