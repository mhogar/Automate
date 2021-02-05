#include "TransformActions.h"
#include "iostream"

TranslateAction::TranslateAction(int durationFrames) : TimedAction(durationFrames) {
}

void TranslateAction::Execute() {
    TimedAction::Execute();

    std::cout << "Translate " << mCurrentFrame << std::endl;
}

OpacityAction::OpacityAction(int durationFrames) : TimedAction(durationFrames) {
}

void OpacityAction::Execute() {
    TimedAction::Execute();

    std::cout << "Opacity " << mCurrentFrame << std::endl;
}
