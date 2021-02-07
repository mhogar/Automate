#ifndef ANIMATION_SDL_FACADE_H
#define ANIMATION_SDL_FACADE_H

class SDL_Window;

class SDLFacade {
    public:
        enum EventType{NONE, QUIT};

        static void Initialize();

        static void OpenWindow();
        static void CloseWindow();

        static EventType GetEvent();
    
    private:
        static SDL_Window* mWindow;
};

#endif
