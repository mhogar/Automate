#pragma once

#include "PreviewWindow.h"
#include <SDL2/SDL.h>

class SDLWindow : public PreviewWindow {
    public:
        SDLWindow();
        virtual ~SDLWindow();
    
    protected:
        virtual void CreateWindow(int width, int height, const char* title);
        virtual void DestroyWindow();

        virtual void Update();

    private:
        SDL_Window* mWindow;
};
