#ifndef ACTORS_ACTOR_DATA_H
#define ACTORS_ACTOR_DATA_H

#include <glm/vec2.hpp>

struct ActorData {
    glm::vec2 Position;
    float Rotation;
    glm::vec2 Scale;
    float Opacity;

    ActorData();
};

ActorData::ActorData() {
    Position.x = 0.0f;
    Position.y = 0.0f;

    Rotation = 0.0f;

    Scale.x = 1.0f;
    Scale.y = 1.0f;

    Opacity = 1.0f;
}

#endif
