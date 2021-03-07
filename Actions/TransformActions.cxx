#include "TransformActions.h"
#include <iostream>

TranslateAction::TranslateAction(Actor* actor, float duration)
    : TimedAction(duration)
{
    mActor = actor;
}

void TranslateAction::Execute() {
    TimedAction::Execute();

    std::cout << "Translate " << mCurrentFrame << std::endl;
}

OpacityAction::OpacityAction(Actor* actor, float duration)
    : TimedAction(duration)
{
    mActor = actor;
}

void OpacityAction::Execute() {
    TimedAction::Execute();

    std::cout << "Opacity " << mCurrentFrame << std::endl;
}
