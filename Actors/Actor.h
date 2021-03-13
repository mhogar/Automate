#pragma once

#include "Actions/Timeline.h"
#include "ActorData.hxx"
#include <list>
#include <glm/mat4x4.hpp>

class Renderer;

class Actor {
    public:
        Actor();
        Actor(Actor* parent, ActorData& data);
        virtual ~Actor();

        void AddAction(ControlAction* action);
        void AddAction(AnimateAction* action);
        void AddChild(Actor* child);

        void Update(float dt);
        void Render(Renderer* renderer);
        void Render(Renderer* renderer, const glm::mat4& parentMat);

        const Timeline* GetTimelineRef() const;
        ActorData* GetActorData() const;
        glm::mat4 GetMatrix() const;

    protected:
        Actor(Actor* parent, ActorData* data);

        virtual void RenderActor(Renderer* renderer) {};
        void BuildMatrix(const glm::mat4& parentMat);

        Actor* mParent;
        std::list<Actor*> mChildActors;
        
        Timeline mTimeline;
        ActorData* mData;
        glm::mat4 mMatrix;
};
