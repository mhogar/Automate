#pragma once

#include "Actors/BoxData.h"

class Actor;

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
