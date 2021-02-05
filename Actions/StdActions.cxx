#include "StdActions.h"
#include <iostream>

DelayAction::DelayAction(int durationFrames) : TimedAction(durationFrames) {
    mIsHalting = true;
}

//-----------------------------------------------------------------------

WaitAction::WaitAction(Animation* parent) {
    mParent = parent;
    mIsHalting = true;
}

bool WaitAction::IsResolved() {
    return false; //TODO: implement
}

//-----------------------------------------------------------------------

RunAsyncAnimationAction::RunAsyncAnimationAction(Animation* parent, Animation animation) {
    mParent = parent;
    mAnimation = animation;
}

void RunAsyncAnimationAction::Initialize() {
    mParent->AddChildAnimation(mAnimation);
}

bool RunAsyncAnimationAction::IsResolved() {
    return true;
}

//-----------------------------------------------------------------------

RunAnimationAction::RunAnimationAction(Animation* parent, Animation animation) : RunAsyncAnimationAction(parent, animation) {
    mIsHalting = true;
}

bool RunAnimationAction::IsResolved() {
    return mAnimation.IsAnimationAndChildrenComplete();
}
