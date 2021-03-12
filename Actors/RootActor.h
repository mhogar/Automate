#ifndef ACTORS_ROOT_ACTOR_H
#define ACTORS_ROOT_ACTOR_H

#include "Actions/Timeline.h"
#include <list>
#include <vector>

class RootActor {
    public:
        virtual ~RootActor() {};

        void AddChildActor(RootActor* child);

        void Update();
        void Render();

        //virtual void RenderActor() = 0;

    protected:
        Timeline mTimeline;
        std::list<RootActor*> mChildActors;
};

#endif
