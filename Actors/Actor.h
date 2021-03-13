#ifndef ACTORS_ACTOR_H
#define ACTORS_ACTOR_H

#include "Actions/Timeline.h"
#include "ActorData.hxx"
#include <list>
#include <glm/mat3x3.hpp>

class Actor {
    public:
        Actor();
        Actor(Actor* parent, ActorData& data);
        virtual ~Actor();

        void AddAction(ControlAction* action);
        void AddAction(AnimateAction* action);
        void AddChild(Actor* child);
        
        void BuildMatrix();

        void Update(float dt);
        void Render();

        const Timeline* GetTimelineRef() const;
        ActorData* GetActorData() const;
        glm::mat3x3 GetMatrix() const;

    protected:
        Actor(Actor* parent, ActorData* data);

        Actor* mParent;
        std::list<Actor*> mChildActors;
        
        Timeline mTimeline;
        ActorData* mData;
        glm::mat3x3 mMatrix;
};

#endif
