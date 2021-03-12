#include "BoxActor.h"

BoxActor::BoxActor(RootActor* parent, BoxData& data) : BoxActor(parent, new BoxData(data)) {
}

BoxActor::BoxActor(RootActor* parent, BoxData* data) : Actor(parent, data) {
}

BoxData* BoxActor::GetBoxData() const {
    return static_cast<BoxData*>(mData);
}
