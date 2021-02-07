#include "AnimationRenderer.h"
#include "SDLFacade.h"

std::list<Action*> AnimationRenderer::mActiveActions;
int AnimationRenderer::mFrameRate = 30;

void AnimationRenderer::Initialize(int framerate) {
    SDLFacade::Initialize();
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

    SDLFacade::OpenWindow();

    while (!animation.IsAnimationComplete()) {
        mActiveActions.splice(mActiveActions.end(), animation.GetNextActions());

        ResolveActions(animation);
        RenderFrame();
    }

    SDLFacade::CloseWindow();
}

void AnimationRenderer::ResolveActions(Animation& animation) {
    std::list<Action*> resolvedActions;

    for (Action* action : mActiveActions) {
        action->Execute();

        if (action->IsResolved()) {
            resolvedActions.push_back(action);
            action->NotifyParentActionResolved();
        }
    }

    for (Action* action : resolvedActions) {
        mActiveActions.remove(action);
    }
}

void AnimationRenderer::RenderFrame() {
    // TODO: render frame using actors
}