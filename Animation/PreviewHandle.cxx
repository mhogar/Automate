#include "PreviewHandle.h"
#include "GraphicsImpl.h"

void PreviewHandle::PreviewAnimation(Animation& animation, int framerate) {
    animation.Initialize(framerate);

    GraphicsImpl* graphicsImpl = GraphicsImplFactory::GetGraphicsImpl();
    graphicsImpl->OpenWindow();

    bool running = true;
    while (running) {
        animation.Update();
        animation.Render();

        running = !animation.IsComplete();
    }

    graphicsImpl->CloseWindow();
}