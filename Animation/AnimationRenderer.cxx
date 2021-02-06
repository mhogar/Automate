#include "AnimationRenderer.h"

std::list<Action*> AnimationRenderer::mActiveActions;
int AnimationRenderer::mFrameRate = 30;

void AnimationRenderer::ConfigureFrameRate(int framerate) {
    mFrameRate = framerate;
}

int AnimationRenderer::GetFrameRate() {
    return mFrameRate;
}

void AnimationRenderer::RenderAnimation(Animation& animation) {
    animation.Initialize();

    while (!animation.IsAnimationComplete()) {
        mActiveActions.splice(mActiveActions.end(), animation.GetNextActions());

        ResolveActions(animation);
        RenderFrame();
    }
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