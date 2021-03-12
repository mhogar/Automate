#ifndef ACTORS_BOX_ACTOR_H
#define ACTORS_BOX_ACTOR_H

#include "Actor.h"
#include "BoxData.hxx"

class BoxActor : public Actor {
    public:
        BoxActor(RootActor* parent, BoxData& data);
        virtual ~BoxActor() {};

        BoxData* GetBoxData() const;

    protected:
        BoxActor(RootActor* parent, BoxData* data);
};

#endif
