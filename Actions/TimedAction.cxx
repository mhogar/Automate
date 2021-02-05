#include "TimedAction.h"
#include <iostream>

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
