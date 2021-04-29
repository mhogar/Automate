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
    if (mThread.has_value()) {
        mThread.value().join();
    }
}

bool PreviewWindow::IsOpen() const {
    return mWindowOpen;
}
