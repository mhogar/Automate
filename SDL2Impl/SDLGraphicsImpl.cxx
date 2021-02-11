#include "SDLGraphicsImpl.h"

GraphicsImpl* GraphicsImplFactory::CreateGraphicsImpl() {
    return new SDLGraphicsImpl();
}

SDLGraphicsImpl::SDLGraphicsImpl() {
    SDL_Init(SDL_INIT_VIDEO);
}

void SDLGraphicsImpl::OpenWindow() {
    mWindow = SDL_CreateWindow("My SDL Empty Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
}

void SDLGraphicsImpl::CloseWindow() {
    SDL_Delay(1500);
    SDL_Quit();
}
