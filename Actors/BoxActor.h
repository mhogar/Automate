#pragma once

#include "Actor.h"
#include "BoxData.hxx"

class BoxActor : public Actor {
    public:
        BoxActor(Actor* parent, BoxData& data);
        virtual ~BoxActor() {};

        BoxData* GetBoxData() const;

    protected:
        BoxActor(Actor* parent, BoxData* data);
        virtual void RenderActor(Renderer* renderer);
};
