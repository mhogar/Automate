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
    glm::vec2 targetPos;
    targetPos.x = targetX;
    targetPos.y = targetY;

    mActor->AddAction(new TranslateAction(&(mActor->GetActorData()->Position), targetPos, duration)); //TODO: Add new add action method that operates on parent
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
