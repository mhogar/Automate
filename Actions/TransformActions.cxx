#include "TransformActions.h"
#include <iostream>

TranslateAction::TranslateAction(ActorData* data, float duration)
    : TimedAction(duration)
{
    mData = data;
}

void TranslateAction::Execute() {
    TimedAction::Execute();

    std::cout << "Translate " << mCurrentFrame << std::endl;
}

OpacityAction::OpacityAction(ActorData* data, float duration)
    : TimedAction(duration)
{
    mData = data;
}

void OpacityAction::Execute() {
    TimedAction::Execute();

    std::cout << "Opacity " << mCurrentFrame << std::endl;
}
