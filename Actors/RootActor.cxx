#include "RootActor.h"

RootActor::~RootActor() {
    for (RootActor* child : mChildActors) {
        delete child;
    }
}

const Timeline* RootActor::GetTimelineRef() const {
    return &mTimeline;
};

void RootActor::AddAction(Action* action) {
    mTimeline.AddAction(action);
}

void RootActor::AddChild(RootActor* child) {
    mChildActors.push_back(child);
}

void RootActor::Update() {
    mTimeline.Update();
}

void RootActor::Render() {
    
}
