#include "Action.h"
#include "Animation/AnimationRenderer.h"

Action::Action(Animation* parent) {
    mParent = parent;
    mIsHalting = false;
}

bool Action::IsHalting() {
    return mIsHalting;
}

void Action::NotifyParentActionResolved() {
    mParent->NotifyActionResolved();
}

//-----------------------------------------------------------------------

TimedAction::TimedAction(Animation* parent, int duration)
    : Action(parent)
{
    mDuration = duration;
}

void TimedAction::Initialize() {
    mCurrentFrame = 0;
}

void TimedAction::Execute() {
    mCurrentFrame++;
}

bool TimedAction::IsResolved() {
    return mCurrentFrame >= mDuration * AnimationRenderer::GetFrameRate();
}
