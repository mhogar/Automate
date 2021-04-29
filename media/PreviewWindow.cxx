#include "PreviewWindow.h"

PreviewWindow::PreviewWindow() {
    mWindowOpen = false;
}

void PreviewWindow::Open(int width, int height, const char* title) {
    if (IsOpen()) {
        return;
    }

    CreateWindow(width, height, title);
    mWindowOpen = true;

    mShouldQuit = false;
    mThread = std::thread([this]() {
        while (!mShouldQuit) {
            Update();
        }

        DestroyWindow();
        mWindowOpen = false;
    });
}

void PreviewWindow::Close() {
    mShouldQuit = true;
}

bool PreviewWindow::IsOpen() const {
    return mWindowOpen;
}
