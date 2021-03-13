#pragma once

#include "Actors/Actor.h"
#include "Actors/ActorData.hxx"
#include "Actors/BoxData.hxx"

class ActorAnimator {
    public:
        ActorAnimator(Actor* actor);
        virtual ~ActorAnimator() {}

        void Delay(float duration);
        void Wait();

        void Translate(float targetX, float targetY, float duration);
        void Rotate(float targetAngle, float duration);
        void Scale(float targetScaleX, float targetScaleY, float duration);
        void Opacity(float targetOpacity, float duration);

        ActorAnimator AddActorChild(ActorData& data);
        ActorAnimator AddBoxChild(BoxData& data);

    protected:
        Actor* mActor;
};
