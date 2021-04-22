#include "SDLWindow.h"

SDLWindow::SDLWindow(int width, int height, const char* title) {
    mShouldClose = false;
    mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
}

void SDLWindow::PollEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        mShouldClose = true;
    }
}

bool SDLWindow::ShouldClose() {
    return mShouldClose;
}

void SDLWindow::Close() {
    if (mWindow != nullptr) {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }
}
