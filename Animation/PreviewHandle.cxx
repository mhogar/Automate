#include "PreviewHandle.h"
#include "GraphicsFacade/GraphicsFactory.h"

void PreviewHandle::PreviewAnimation(Animation& animation, int framerate) {
    animation.Initialize(framerate);

    auto window = GraphicsFactory::GetInstance()->CreateWindow();
    window->CreateWindow(600, 600, "Animation Preview");

    while (!window->ShouldClose()) {
        window->PollEvents();

        animation.Update();
        animation.Render();
    }

    window->DestroyWindow();
}