#include "Action.h"

bool Action::IsHalting() const {
    return mIsHalting;
}

//-----------------------------------------------------------------------

TimedAction::TimedAction(float duration) {
    mDuration = duration;
}

void TimedAction::Initialize() {
    mCurrentFrame = 0;
}

void TimedAction::Execute() {
    mCurrentFrame++;
}

bool TimedAction::IsResolved() const {
    return mCurrentFrame >= mDuration;
}
