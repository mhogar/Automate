#include "PreviewWindow.h"

PreviewWindow::PreviewWindow() {
    mWindowOpen = false;
}

void PreviewWindow::Open() {
    if (IsOpen()) {
        return;
    }

    OpenWindow();
    mWindowOpen = true;
    
    // join the thread first if one was running
    if (mThread.has_value()) {
        mThread.value().join();
    }

    // start a new thread for window updates
    mShouldQuit = false;
    mThread = std::thread([this]() {
        while (!mShouldQuit) {
            Update();
        }

        CloseWindow();
        mWindowOpen = false;
    });
}

void PreviewWindow::Close() {
    if (!IsOpen()) {
        return;
    }

    mShouldQuit = true;
    mThread.value().join();
    mThread.reset();
}

bool PreviewWindow::IsOpen() const {
    return mWindowOpen;
}
