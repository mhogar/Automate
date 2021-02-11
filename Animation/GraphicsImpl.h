# ifndef ANIMATION_GRAPHICS_IMPL_H
#define ANIMATION_GRAPHICS_IMPL_H

class GraphicsImpl {
    public:
        virtual void OpenWindow() = 0;
        virtual void CloseWindow() = 0;
};

class GraphicsImplFactory {
    public:
        // To be implemented by specific implementation
        static GraphicsImpl* GetGraphicsImpl();

    private:
        static GraphicsImpl* CreateGraphicsImpl();
        static GraphicsImpl* mInstance;
};

#endif
