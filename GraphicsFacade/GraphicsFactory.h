#ifndef GF_GRAPHICS_FACTORY_H
#define GF_GRAPHICS_FACTORY_H

#include "GraphicsWindow.h"
#include "GraphicsRenderer.h"
#include <memory>

class GraphicsFactory {
    public:
        static GraphicsFactory* GetInstance();
        
        virtual std::shared_ptr<GraphicsWindow> CreateWindow() = 0;

    protected:
        GraphicsFactory() {};

    private:
        static std::unique_ptr<GraphicsFactory> mInstance;

        //-- To be implemented by specific implementation --
        static GraphicsFactory* CreateGraphicsFactory();
};

#endif
