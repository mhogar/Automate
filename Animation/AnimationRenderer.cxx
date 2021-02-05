#include "AnimationRenderer.h"

AnimationRenderer::AnimationRenderer() {
}

void AnimationRenderer::Render() {
    bool allAnimationsFinished;
    do {
        allAnimationsFinished = true;

        for (Animation animation : mAnimations) {
            RenderAnimation(animation);
            if (animation.HasNextAction()) {
                allAnimationsFinished = false;
            }
        }

        RenderFrame();
    } while (!allAnimationsFinished);
}

void AnimationRenderer::RenderAnimation(Animation animation) {
    while (animation.HasNextAction()) {
        Action* action = animation.GetAction();

        if (mActiveActions.find(action) != mActiveActions.end()) {
            action->Initialize();
            mActiveActions.insert(action);
        }

        if (action->IsHalting() && !action->IsResolved()) {
            break;
        }
        animation.NextAction();
    }
}

void AnimationRenderer::RenderFrame() {
    std::list<Action*> resolvedActions;

    for (Action* action : mActiveActions) {
        if (action->IsResolved()) {
            resolvedActions.push_back(action);
            continue;
        }

        action->Execute();
    }

    for (Action* action : resolvedActions) {
        mActiveActions.erase(action);
    }

    // TODO: render frame using actors
}