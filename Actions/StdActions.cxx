#include "StdActions.h"
#include <iostream>

DelayAction::DelayAction(int durationFrames)
    : TimedAction(durationFrames)
{
    mIsHalting = true;
}

//-----------------------------------------------------------------------

WaitAction::WaitAction(const Animation* parent) {
    mParent = parent;
    mIsHalting = true;
}

bool WaitAction::IsResolved() {
    return !mParent->HasActiveActions();
}

//-----------------------------------------------------------------------

RunAsyncAnimationAction::RunAsyncAnimationAction(Animation* parent, Animation* animation) {
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

RunAnimationAction::RunAnimationAction(Animation* parent, Animation* animation)
    : RunAsyncAnimationAction(parent, animation)
{
    mIsHalting = true;
}

bool RunAnimationAction::IsResolved() {
    return mAnimation->IsAnimationComplete();
}
