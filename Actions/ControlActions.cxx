#include "ControlActions.h"
#include <iostream>

DelayAction::DelayAction(float duration) {
    mDuration = duration;
    mIsHalting = true;
}

void DelayAction::Initialize() {
    mTimer = 0;
}

void DelayAction::Execute(float dt) {
    mTimer += dt;
}

bool DelayAction::IsResolved() const {
    return mTimer >= mDuration;
}

//-----------------------------------------------------------------------

WaitAction::WaitAction(const Timeline* timeline) {
    mTimeline = timeline;
    mIsHalting = true;
}

bool WaitAction::IsResolved() const {
    return mTimeline->GetNumActiveActions() <= 1; // the 1 is this wait action
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
