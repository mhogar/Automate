#include "ActorAnimator.h"
#include "Actions/ControlActions.h"
#include "Actions/TransformActions.h"
#include "Actors/BoxActor.h"

ActorAnimator::ActorAnimator(Actor* actor) {
    mActor = actor;
}

void ActorAnimator::Delay(float duration) {
    mActor->AddAction(new DelayAction(duration));
}

void ActorAnimator::Wait() {
    mActor->AddAction(new WaitAction(mActor->GetTimelineRef()));
}

void ActorAnimator::Translate(float targetX, float targetY, float duration) {
    mActor->AddAction(new TranslateAction(&(mActor->GetActorData()->Position), glm::vec3(targetX, targetY, 0.0f), duration));
}

void ActorAnimator::Rotate(float targetAngle, float duration) {
    mActor->AddAction(new RotateAction(&(mActor->GetActorData()->Rotation), glm::vec3(0.0f, 0.0f, targetAngle), duration));
}

void ActorAnimator::Scale(float targetScaleX, float targetScaleY, float duration) {
    mActor->AddAction(new ScaleAction(&(mActor->GetActorData()->Scale), glm::vec3(targetScaleX, targetScaleY, 1.0f), duration));
}

void ActorAnimator::Opacity(float targetOpacity, float duration) {
    mActor->AddAction(new OpacityAction(&(mActor->GetActorData()->Opacity), targetOpacity, duration));
}

ActorAnimator ActorAnimator::AddActorChild(ActorData& data) {
    Actor* actor = new Actor(mActor, data);
    mActor->AddChild(actor);
    return ActorAnimator(actor);
}

ActorAnimator ActorAnimator::AddBoxChild(BoxData& data) {
    BoxActor* box = new BoxActor(mActor, data);
    mActor->AddChild(box);
    return ActorAnimator(box);
}
