#include "ConsoleInput.h"

ConsoleInput::ConsoleInput(std::istream& in) {
    mInputThread = new std::thread([this, &in]() {
        PollInput(in);
    });
}

ConsoleInput::~ConsoleInput() {
    mInputThread->join();
    delete mInputThread;
}

bool ConsoleInput::HasInput() {
    return mChannel.HasData();
}

std::vector<std::string> ConsoleInput::GetInput() {
    return mChannel.PopData();
}

void ConsoleInput::PollInput(std::istream& in) {
    // wait for a line to be available
    std::string line = "";
    std::getline(in, line);

    if (line == "") {
        return;
    }

    // push the line to the channel
    mChannel.PushData(line);
}
