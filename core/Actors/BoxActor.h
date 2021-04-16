#pragma once

#include "Actor.h"
#include "BoxData.h"

class BoxActor : public Actor {
    public:
        BoxActor(Actor* parent, BoxData& data);
        virtual ~BoxActor() {};

        const char* Colour;

    protected:
        virtual void RenderActor(Renderer* renderer);
};
