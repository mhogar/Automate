#include "RootAnimator.h"
#include "ActorAnimator.h"
#include "Actions/StdActions.h"
#include "Actors/Actor.h"
#include "Actors/BoxActor.h"

RootAnimator::RootAnimator(RootActor* actor) {
    mActor = actor;
}

void RootAnimator::Delay(float duration) {
    mActor->AddAction(new DelayAction(duration));
}

void RootAnimator::Wait() {
    mActor->AddAction(new WaitAction(mActor->GetTimelineRef()));
}

ActorAnimator RootAnimator::AddActorChild(ActorData& data) {
    Actor* actor = new Actor(mActor, data);
    mActor->AddChild(actor);
    return ActorAnimator(actor);
}

ActorAnimator RootAnimator::AddBoxChild(BoxData& data) {
    BoxActor* box = new BoxActor(mActor, data);
    mActor->AddChild(box);
    return ActorAnimator(box);
}
