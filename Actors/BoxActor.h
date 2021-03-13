#ifndef ACTORS_BOX_ACTOR_H
#define ACTORS_BOX_ACTOR_H

#include "Actor.h"
#include "BoxData.hxx"

class BoxActor : public Actor {
    public:
        BoxActor(Actor* parent, BoxData& data);
        virtual ~BoxActor() {};

        BoxData* GetBoxData() const;

    protected:
        BoxActor(Actor* parent, BoxData* data);
};

#endif
