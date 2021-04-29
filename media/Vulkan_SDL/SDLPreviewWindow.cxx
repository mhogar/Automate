#include "SDLPreviewWindow.h"

SDLPreviewWindow::SDLPreviewWindow(SDL_Window* window) {
    mWindow = window;
    Open();
}

SDLPreviewWindow::~SDLPreviewWindow() {
    Close();
}

void SDLPreviewWindow::OpenWindow() {
    SDL_ShowWindow(mWindow);
}

void SDLPreviewWindow::CloseWindow() {
    SDL_HideWindow(mWindow);
}

void SDLPreviewWindow::Update() {
    // handle events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            mShouldQuit = true;
        }
        else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
            mShouldQuit = true;
        }
    }

    // do rendering stuff
}
