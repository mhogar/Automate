#include "AnimationRenderer.h"

void AnimationRenderer::RenderAnimation(Animation animation) {
    while (!animation.IsAnimationAndChildrenComplete()) {
        mActiveActions.splice(mActiveActions.end(), animation.GetNextActions());

        ResolveActions();
        RenderFrame();
    }
}

void AnimationRenderer::ResolveActions() {
    std::list<Action*> resolvedActions;

    for (Action* action : mActiveActions) {
        action->Execute();

        if (action->IsResolved()) {
            resolvedActions.push_back(action);
        }
    }

    for (Action* action : resolvedActions) {
        mActiveActions.remove(action);
    }
}

void AnimationRenderer::RenderFrame() {
    // TODO: render frame using actors
}