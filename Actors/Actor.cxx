#include "Actor.h"
#include <glm/ext/matrix_transform.hpp>

Actor::Actor() : Actor(nullptr, ActorData()) {
}

Actor::Actor(Actor* parent, const ActorData& data) {
    mParent = parent;

    Position = glm::vec3(data.PositionX, data.PositionY, data.PositionZ);
    Rotation = glm::vec3(data.RotationX, data.RotationY, data.RotationZ);
    Scale = glm::vec3(data.ScaleX, data.ScaleY, data.ScaleZ);
    Opacity = data.Opacity;
}

Actor::~Actor() {
    for (Actor* child : mChildActors) {
        delete child;
    }
}

void Actor::AddAction(ControlAction* action) {
    mTimeline.AddAction(action);
}

void Actor::AddAction(AnimateAction* action) {
    if (mParent != nullptr) {
        mParent->mTimeline.AddAction(action);
    }
    else {
        mTimeline.AddAction(action);
    }
}

void Actor::AddChild(Actor* child) {
    mChildActors.push_back(child);
}

void Actor::Update(float dt) {
    mTimeline.Update(dt);

    for (Actor* child : mChildActors) {
        child->Update(dt);
    }
}

void Actor::Render(Renderer* renderer) {
    Render(renderer, glm::identity<glm::mat4>());
}

void Actor::Render(Renderer* renderer, const glm::mat4& parentMat) {
    BuildMatrix(parentMat);

    RenderActor(renderer);

    for (Actor* child : mChildActors) {
        child->Render(renderer, mMatrix);
    }
}

const Timeline* Actor::GetTimelineRef() const {
    return &mTimeline;
};

glm::mat4 Actor::GetMatrix() const {
    return mMatrix;
}

void Actor::BuildMatrix(const glm::mat4& parentMat) {
    mMatrix = glm::scale(parentMat, Scale);
    if (Rotation.x != 0) {
        mMatrix = glm::rotate(mMatrix, glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (Rotation.y != 0) {
        mMatrix = glm::rotate(mMatrix, glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (Rotation.z != 0) {
        mMatrix = glm::rotate(mMatrix, glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    }
    mMatrix = glm::translate(mMatrix, Position);
    mMatrix[3][3] = Opacity;
}
