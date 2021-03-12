#include "Actor.h"

Actor::Actor(RootActor* parent, ActorData& data) : Actor(parent, new ActorData(data)) {
}

Actor::Actor(RootActor* parent, ActorData* data) {
    mParent = parent;
    mData = data;
}

Actor::~Actor() {
    delete mData;
}

ActorData* Actor::GetActorData() {
    return mData;
}
