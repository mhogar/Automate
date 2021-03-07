#include "AnimationRenderer.h"

int AnimationRenderer::mFrameRate = 30;

void AnimationRenderer::Initialize(int framerate) {
    ConfigureFrameRate(framerate);
}

void AnimationRenderer::ConfigureFrameRate(int framerate) {
    mFrameRate = framerate;
}

int AnimationRenderer::GetFrameRate() {
    return mFrameRate;
}

void AnimationRenderer::RenderAnimation(RootActor& root) {
    root.Initialize();

    while (!root.IsAnimationComplete()) {
        root.Update();
        root.Render();
    }
}
