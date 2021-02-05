#include "AnimationBuilder.h"
#include "Actions/StdActions.h"
#include "Actions/TransformActions.h"

AnimationBuilder::AnimationBuilder(int framerate) {
    mFramerate = framerate;
}

Animation AnimationBuilder::FinalizeAnimation() {
    mAnimation.AddAction(new WaitAction(&mAnimation));

    return mAnimation;
}

void AnimationBuilder::Delay(int duration) {
    mAnimation.AddAction(new DelayAction(duration * mFramerate));
}

void AnimationBuilder::RunAnimation(Animation animation) {
    mAnimation.AddAction(new RunAnimationAction(&mAnimation, animation));
}

void AnimationBuilder::RunAsyncAnimation(Animation animation) {
    mAnimation.AddAction(new RunAsyncAnimationAction(&mAnimation, animation));
}

void AnimationBuilder::Translate(int duration) {
    mAnimation.AddAction(new TranslateAction(duration * mFramerate));
}

void AnimationBuilder::Opacity(int duration) {
    mAnimation.AddAction(new OpacityAction(duration * mFramerate));
}
