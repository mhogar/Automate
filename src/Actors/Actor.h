#pragma once

#include "Actions/Timeline.h"
#include "ActorData.h"
#include <list>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Renderer;

class Actor {
    public:
        Actor();
        Actor(Actor* parent, const ActorData& data);
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

        glm::vec3 Position;
        glm::vec3 Rotation;
        glm::vec3 Scale;
        float Opacity;

    protected:
        virtual void RenderActor(Renderer* renderer) {};
        void BuildMatrix(const glm::mat4& parentMat);

        Actor* mParent;
        std::list<Actor*> mChildActors;
        
        Timeline mTimeline;
        glm::mat4 mMatrix;
};
