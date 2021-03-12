#ifndef ANIMATION_ACTOR_ANIMATOR_H
#define ANIMATION_ACTOR_ANIMATOR_H

#include "RootAnimator.h"
#include "Actors/Actor.h"

class ActorAnimator : public RootAnimator {
    public:
        ActorAnimator(Actor* actor);
        virtual ~ActorAnimator() {}

        void Translate(float duration);
        void Opacity(float duration);
};

#endif
