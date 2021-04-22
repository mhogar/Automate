#pragma once

#include "Window.h"
#include <SDL2/SDL.h>

class SDLWindow : public Window {
    public:
        SDLWindow(int width, int height, const char* title);

        virtual void PollEvents();
        virtual bool ShouldClose();
        virtual void Close();
    
    private:
        bool mShouldClose;
        SDL_Window* mWindow;
};
