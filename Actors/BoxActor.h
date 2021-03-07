#ifndef ACTORS_BOX_ACTOR_H
#define ACTORS_BOX_ACTOR_H

#include "Actor.h"

class BoxActor : public Actor {
    public:
        BoxActor();
        BoxActor(float posX, float posY, float rot, float scaleX, float scaleY, float opacity, const char* colour);

        virtual ~BoxActor() {};

        virtual void RenderActor();

        const char* mColour;
};

#endif
