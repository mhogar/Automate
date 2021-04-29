#pragma once

#include "PreviewWindow.h"
#include <SDL2/SDL.h>

class SDLPreviewWindow : public PreviewWindow {
    public:
        SDLPreviewWindow(SDL_Window* window);
        virtual ~SDLPreviewWindow();
    
    protected:
        virtual void OpenWindow();
        virtual void CloseWindow();

        virtual void Update();

    private:
        SDL_Window* mWindow;
};
