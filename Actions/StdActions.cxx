#include "StdActions.h"
#include <iostream>

DelayAction::DelayAction(float duration)
    : TimedAction(duration)
{
    mIsHalting = true;
}

//-----------------------------------------------------------------------

WaitAction::WaitAction(const RootActor* parent) {
    mParent = parent;
    mIsHalting = true;
}

bool WaitAction::IsResolved() const {
    return mParent->GetNumActiveActions() <= 1; // the 1 is this wait action
}

//-----------------------------------------------------------------------

// RunAsyncAnimationAction::RunAsyncAnimationAction(Animation* parent, std::shared_ptr<Animation> animation) {
//     mParent = parent;
//     mAnimation = animation;
// }

// void RunAsyncAnimationAction::Initialize() {
//     mAnimation->Initialize();
//     mParent->AddChildAnimation(mAnimation.get());
// }

// bool RunAsyncAnimationAction::IsResolved() const {
//     return true;
// }

// //-----------------------------------------------------------------------

// RunAnimationAction::RunAnimationAction(Animation* parent, std::shared_ptr<Animation> animation)
//     : RunAsyncAnimationAction(parent, animation)
// {
//     mIsHalting = true;
// }

// bool RunAnimationAction::IsResolved() const {
//     return mAnimation->IsAnimationComplete();
// }
