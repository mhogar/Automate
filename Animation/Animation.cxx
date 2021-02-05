#include "Animation.h"
#include "Actions/StdActions.h"
#include "Actions/TransformActions.h"

Animation::Animation() : Animation(30) {
}

Animation::Animation(int framerate) {
    mFramerate = framerate;
    mActionItr = mActions.begin();
}

void Animation::Delay(int duration) {
    mActions.push_back(new DelayAction(duration * mFramerate));
}

void Animation::Translate(int duration) {
    mActions.push_back(new TranslateAction(duration * mFramerate));
}

void Animation::Opacity(int duration) {
    mActions.push_back(new OpacityAction(duration * mFramerate));
}

Action* Animation::GetAction() {
    return *mActionItr;
}

void Animation::NextAction() {
    mActionItr++;
}

bool Animation::HasNextAction() {
    return mActionItr != mActions.end();
}
