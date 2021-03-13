#include "Actor.h"

Actor::Actor() : Actor(nullptr, new ActorData()) {
}

Actor::Actor(Actor* parent, ActorData& data) : Actor(parent, new ActorData(data)) {
}

Actor::Actor(Actor* parent, ActorData* data) {
    mParent = parent;
    mData = data;
}

Actor::~Actor() {
    delete mData;

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

void Actor::BuildMatrix() {
}

void Actor::Update(float dt) {
    mTimeline.Update(dt);

    for (Actor* child : mChildActors) {
        child->Update(dt);
    }
}

void Actor::Render() {
}

const Timeline* Actor::GetTimelineRef() const {
    return &mTimeline;
};

ActorData* Actor::GetActorData() const {
    return mData;
}

glm::mat3x3 Actor::GetMatrix() const {
    return mMatrix;
}
