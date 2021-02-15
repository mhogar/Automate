#ifndef GF_GRAPHICS_WINDOW_H
#define GF_GRAPHICS_WINDOW_H

class GraphicsWindow {
    public:
        virtual void CreateWindow(int width, int height, const char* title) = 0;
        virtual void DestroyWindow() = 0;

        virtual bool ShouldClose() = 0;
        virtual void PollEvents() = 0;
};

#endif
