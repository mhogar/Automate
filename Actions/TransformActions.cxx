#include "TransformActions.h"
#include <iostream>

TranslateAction::TranslateAction(int duration)
    : TimedAction(duration) {}

void TranslateAction::Execute() {
    TimedAction::Execute();

    std::cout << "Translate " << mCurrentFrame << std::endl;
}

OpacityAction::OpacityAction(int duration)
    : TimedAction( duration) {}

void OpacityAction::Execute() {
    TimedAction::Execute();

    std::cout << "Opacity " << mCurrentFrame << std::endl;
}
