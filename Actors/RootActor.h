#ifndef ACTORS_ROOT_ACTOR_H
#define ACTORS_ROOT_ACTOR_H

#include "Actions/Timeline.h"
#include <list>
#include <vector>

class RootActor {
    public:
        virtual ~RootActor();

        const Timeline* GetTimelineRef() const;

        void AddAction(Action* action);
        void AddChild(RootActor* child);

        void Update();
        void Render();

    protected:
        Timeline mTimeline;
        std::list<RootActor*> mChildActors;
};

#endif
