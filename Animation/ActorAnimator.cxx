#include "ActorAnimator.h"
#include "TransformActions.h"

ActorAnimator::ActorAnimator(Actor* actor) : RootAnimator(actor) {
}

void ActorAnimator::Translate(float duration) {
    Actor* actor = static_cast<Actor*>(mActor);
    actor->GetParent()->AddAction(new TranslateAction(actor->GetActorData(), duration));
}

void ActorAnimator::Opacity(float duration) {
    Actor* actor = static_cast<Actor*>(mActor);
    actor->GetParent()->AddAction(new OpacityAction(actor->GetActorData(), duration));
}
