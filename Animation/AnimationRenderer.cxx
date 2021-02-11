#include "AnimationRenderer.h"
#include "SDLFacade.h"

std::list<Action*> AnimationRenderer::mActiveActions;
int AnimationRenderer::mFrameRate = 30;

void AnimationRenderer::Initialize(int framerate) {
    //SDLFacade::Initialize();
    ConfigureFrameRate(framerate);
}

void AnimationRenderer::ConfigureFrameRate(int framerate) {
    mFrameRate = framerate;
}

int AnimationRenderer::GetFrameRate() {
    return mFrameRate;
}

void AnimationRenderer::RenderAnimation(Animation& animation) {
    animation.Initialize();

    //SDLFacade::OpenWindow();

    while (!animation.IsAnimationComplete()) {
        animation.Update();
        animation.Render();
    }

    //SDLFacade::CloseWindow();
}