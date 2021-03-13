#include "BoxActor.h"

BoxActor::BoxActor(Actor* parent, BoxData& data) : BoxActor(parent, new BoxData(data)) {
}

BoxActor::BoxActor(Actor* parent, BoxData* data) : Actor(parent, data) {
}

BoxData* BoxActor::GetBoxData() const {
    return static_cast<BoxData*>(mData);
}
