#include "AnimationRenderer.h"

void AnimationRenderer::RenderAnimation(Animation& animation) {
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
            animation.NotifyActionResolved(action);
        }
    }

    for (Action* action : resolvedActions) {
        mActiveActions.remove(action);
    }
}

void AnimationRenderer::RenderFrame() {
    // TODO: render frame using actors
}