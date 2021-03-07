#ifndef ACTORS_ACTOR_H
#define ACTORS_ACTOR_H

#include "RootActor.h"
#include <glm/vec2.hpp>

class Actor : public RootActor {
    public:
        Actor();
        Actor(float posX, float posY, float rot, float scaleX, float scaleY, float opacity);
        
        virtual ~Actor() {};

        virtual void RenderActor() = 0;

        void Translate(float duration);
        void Opacity(float duration);

        glm::vec2 mPosition;
        float mRotation;
        glm::vec2 mScale;
        float mOpacity;
};

#endif
