#include "GPUShell.h"

GPUShell::GPUShell(std::istream& in, std::ostream& out)
    : Shell(in, out)
{
    mGPUInfos = GraphicsFacade::Instance()->GetGPUDeviceList();
    mSelectedGPUIndex = GraphicsFacade::Instance()->GetSelectedGPUIndex();

    mCommands.insert({
        std::pair<std::string, Command>("list",
            {
                "list all GPUs", {},
                [this](const std::vector<std::string>& args) { HandleListCommand(args); }
            }
        ),
        std::pair<std::string, Command>("select",
            {
                "select a GPU by its index",
                {
                    { "index", "the index to select", true },
                },
                [this](const std::vector<std::string>& args) { HandleSelectCommand(args); }
            }
        ),
    });
}

void GPUShell::Update() {
    mOut << "gpu > ";
    HandleInput();
}

void GPUShell::HandleListCommand(const std::vector<std::string>& args) {
    PrintGPUList();
}

void GPUShell::HandleSelectCommand(const std::vector<std::string>& args) {
    int index = -1;

    // parse new index from args
    try {
        index = std::stoi(args[1]);
    }
    catch (std::invalid_argument& e) {}

    // check index is valid and select the GPU
    if (index < 0 || index >= mGPUInfos.size()) {
        Indent(1) << "invalid index\n";
    }
    else {
        mSelectedGPUIndex = index;
        GraphicsFacade::Instance()->SelectGPU(index);
        Indent(1) << "selected \"" << mGPUInfos[index].Name << "\"\n";
    }
}

void GPUShell::PrintGPUList() {
    for (int i = 0; i < mGPUInfos.size(); i++) {
        Indent(1) << i << ": " << mGPUInfos[i].Name << " (compatibility list)";
        mOut << (i == mSelectedGPUIndex ? " <- selected\n" : "\n");
    }
}
