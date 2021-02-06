#include "StdActions.h"
#include <iostream>

DelayAction::DelayAction(Animation* parent, int duration)
    : TimedAction(parent, duration)
{
    mIsHalting = true;
}

//-----------------------------------------------------------------------

WaitAction::WaitAction(Animation* parent)
    : Action(parent)
{
    mIsHalting = true;
}

bool WaitAction::IsResolved() {
    return mParent->GetNumActiveActions() <= 1; // the 1 is this wait action
}

//-----------------------------------------------------------------------

RunAsyncAnimationAction::RunAsyncAnimationAction(Animation* parent, std::shared_ptr<Animation> animation)
    : Action(parent)
{
    mAnimation = animation;
}

void RunAsyncAnimationAction::Initialize() {
    mAnimation->Initialize();
    mParent->AddChildAnimation(mAnimation.get());
}

bool RunAsyncAnimationAction::IsResolved() {
    return true;
}

//-----------------------------------------------------------------------

RunAnimationAction::RunAnimationAction(Animation* parent, std::shared_ptr<Animation> animation)
    : RunAsyncAnimationAction(parent, animation)
{
    mIsHalting = true;
}

bool RunAnimationAction::IsResolved() {
    return mAnimation->IsAnimationComplete();
}
