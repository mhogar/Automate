#include "Animation/GraphicsImpl.h"
#include <SDL2/SDL.h>

class SDLGraphicsImpl : public GraphicsImpl {
    public:
        SDLGraphicsImpl();

        virtual void OpenWindow();
        virtual void CloseWindow();
    
    private:
        SDL_Window* mWindow;
};
