#ifndef ACTORS_ACTOR_H
#define ACTORS_ACTOR_H

#include "RootActor.h"
#include "ActorData.hxx"

class Actor : public RootActor {
    public:
        Actor(RootActor* parent, ActorData& data);
        virtual ~Actor();

        ActorData* GetActorData();

    protected:
        Actor(RootActor* parent, ActorData* data);

        RootActor* mParent;
        ActorData* mData;
};

#endif
