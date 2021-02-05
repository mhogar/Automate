#include "Animation.h"
#include "Actions/StdActions.h"
#include "Actions/TransformActions.h"

Animation::Animation() : Animation(30) {
}

Animation::Animation(int framerate) {
    mFramerate = framerate;
    mActionItr = mActions.begin();
    mIsHalted = false;
}

void Animation::Delay(int duration) {
    mActions.push_back(new DelayAction(duration * mFramerate));
}

void Animation::Translate(int duration) {
    mActions.push_back(new TranslateAction(duration * mFramerate));
}

void Animation::Opacity(int duration) {
    mActions.push_back(new OpacityAction(duration * mFramerate));
}

void Animation::AddChildAnimation(Animation child) {
    mChildAnimations.push_back(child);
}

std::list<Action*> Animation::GetNextActions() {
    std::list<Action*> actions;

    while (!IsAnimationComplete()) {
        Action* action = *mActionItr;

        if (mIsHalted && !action->IsResolved()) {
            break;
        }
        mIsHalted = false;

        action->Initialize();
        actions.push_back(action);

        if (action->IsHalting()) {
            mIsHalted = true;
            break;
        }

        mActionItr++;
    }

    for (Animation& child : mChildAnimations) {
        actions.splice(actions.end(), child.GetNextActions());
    }

    return actions;
}

bool Animation::IsAnimationComplete() {
    return mActionItr == mActions.end();
}

bool Animation::IsAnimationAndChildrenComplete() {
    if (!IsAnimationComplete()) {
        return false;
    }

    for (Animation& child : mChildAnimations) {
        if (!child.IsAnimationAndChildrenComplete()) {
            return false;
        }
    }
    
    return true;
}
