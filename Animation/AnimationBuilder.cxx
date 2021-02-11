#include "AnimationBuilder.h"
#include "Actions/StdActions.h"
#include "Actions/TransformActions.h"

AnimationBuilder::AnimationBuilder() {
    mAnimation = std::shared_ptr<Animation>(new Animation());
}

std::shared_ptr<Animation> AnimationBuilder::GetAnimation() const {
    return mAnimation;
}

void AnimationBuilder::Delay(int duration) {
    mAnimation->AddAction(new DelayAction(mAnimation.get(), duration));
}

void AnimationBuilder::Wait() {
    mAnimation->AddAction(new WaitAction(mAnimation.get()));
}

void AnimationBuilder::Run(std::shared_ptr<Animation>animation) {
    mAnimation->AddAction(new RunAnimationAction(mAnimation.get(), animation));
}

void AnimationBuilder::RunAsync(std::shared_ptr<Animation> animation) {
    mAnimation->AddAction(new RunAsyncAnimationAction(mAnimation.get(), animation));
}

void AnimationBuilder::Translate(int duration) {
    mAnimation->AddAction(new TranslateAction(mAnimation.get(), duration));
}

void AnimationBuilder::Opacity(int duration) {
    mAnimation->AddAction(new OpacityAction(mAnimation.get(), duration));
}
