#include "Action.h"

bool Action::IsHalting() const {
    return mIsHalting;
}

//-----------------------------------------------------------------------

TimedAction::TimedAction(const Animation* parent, int duration) {
    mParent = parent;
    mDuration = duration;
}

void TimedAction::Initialize() {
    mCurrentFrame = 0;
}

void TimedAction::Execute() {
    mCurrentFrame++;
}

bool TimedAction::IsResolved() const {
    return mCurrentFrame >= mDuration * mParent->GetFrameRate();
}
