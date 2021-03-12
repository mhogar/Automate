#include "RootActor.h"

RootActor::~RootActor() {
    for (RootActor* child : mChildActors) {
        delete child;
    }
}

void RootActor::AddChildActor(RootActor* child) {
    mChildActors.push_back(child);
}

void RootActor::Update() {
    mTimeline.Update();
}

void RootActor::Render() {
    
}
