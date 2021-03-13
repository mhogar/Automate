#include "BoxActor.h"
#include "Renderer/Renderer.h"

BoxActor::BoxActor(Actor* parent, BoxData& data) : BoxActor(parent, new BoxData(data)) {
}

BoxActor::BoxActor(Actor* parent, BoxData* data) : Actor(parent, data) {
}

void BoxActor::RenderActor(Renderer* renderer) {
    renderer->Render(*this);
}

BoxData* BoxActor::GetBoxData() const {
    return static_cast<BoxData*>(mData);
}
