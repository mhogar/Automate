#include "SDLFacade.h"
#include <SDL2/SDL.h>

SDL_Window* SDLFacade::mWindow;

void SDLFacade::Initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    
}

void SDLFacade::OpenWindow() {
    mWindow = SDL_CreateWindow("My SDL Empty Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);   
}

void SDLFacade::CloseWindow() {
    SDL_Delay(3000);
    SDL_Quit();
}

SDLFacade::EventType SDLFacade::GetEvent() {
    
}
