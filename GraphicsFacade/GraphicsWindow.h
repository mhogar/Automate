#ifndef GF_GRAPHICS_WINDOW_H
#define GF_GRAPHICS_WINDOW_H

#include "GraphicsRenderer.h"

class GraphicsWindow {
    public:
        virtual void CreateWindow(int width, int height, const char* title) = 0;
        virtual void DestroyWindow() = 0;

        virtual bool ShouldClose() = 0;
        virtual void PollEvents() = 0;

        GraphicsRenderer* GetRenderer() const;

    protected:
        GraphicsRenderer* mRenderer;
};

#endif
