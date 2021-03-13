#pragma once

#include <glm/vec3.hpp>

struct ActorData {
    glm::vec3 Position;
    glm::vec3 Rotation;
    glm::vec3 Scale;
    float Opacity;

    ActorData() {
        Position = glm::vec3(0.0f);
        Rotation = glm::vec3(0.0f);
        Scale = glm::vec3(1.0f);
        Opacity = 1.0f;
    }
};
