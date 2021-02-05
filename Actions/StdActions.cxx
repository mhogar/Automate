#include "StdActions.h"

DelayAction::DelayAction(int durationFrames) : TimedAction(durationFrames) {
    mIsHalting = true;
}
