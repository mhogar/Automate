#ifndef ANIMATION_ROOT_ANIMATOR_H
#define ANIMATION_ROOT_ANIMATOR_H

#include "Actors/RootActor.h"
#include "Actors/ActorData.hxx"
#include "Actors/BoxData.hxx"

class ActorAnimator;

class RootAnimator {
    public:
        RootAnimator(RootActor* actor);
        virtual ~RootAnimator() {};

        void Delay(float duration);
        void Wait();

        ActorAnimator AddActorChild(ActorData& data);
        ActorAnimator AddBoxChild(BoxData& data);

    protected:
        RootActor* mActor;
};

#endif
