#include "SDLWindow.h"

SDLWindow::SDLWindow() {
    mWindow = nullptr;
}

SDLWindow::~SDLWindow() {
    //Close();
}

void SDLWindow::CreateWindow(int width, int height, const char* title) {
    mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
}

void SDLWindow::DestroyWindow() {
    if (mWindow != nullptr) {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }
}

void SDLWindow::Update() {
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
