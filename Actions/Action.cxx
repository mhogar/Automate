#include "Action.h"

bool Action::IsHalting() {
    return mIsHalting;
}

//-----------------------------------------------------------------------

TimedAction::TimedAction(int durationFrames) {
    mDurationFrames = durationFrames;
}

void TimedAction::Initialize() {
    mCurrentFrame = 0;
}

void TimedAction::Execute() {
    mCurrentFrame++;
}

bool TimedAction::IsResolved() {
    return mCurrentFrame >= mDurationFrames;
}
