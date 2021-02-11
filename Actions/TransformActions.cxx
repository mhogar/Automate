#include "TransformActions.h"
#include <iostream>

TranslateAction::TranslateAction(const Animation* parent, int duration)
    : TimedAction(parent, duration) {}

void TranslateAction::Execute() {
    TimedAction::Execute();

    std::cout << "Translate " << mCurrentFrame << std::endl;
}

OpacityAction::OpacityAction(const Animation* parent, int duration)
    : TimedAction(parent, duration) {}

void OpacityAction::Execute() {
    TimedAction::Execute();

    std::cout << "Opacity " << mCurrentFrame << std::endl;
}
