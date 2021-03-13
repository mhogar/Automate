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
