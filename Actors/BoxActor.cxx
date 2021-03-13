#include "BoxActor.h"
#include "Renderer/Renderer.h"

BoxActor::BoxActor(Actor* parent, BoxData& data) : Actor(parent, data) {
    Colour = data.Colour;
}

void BoxActor::RenderActor(Renderer* renderer) {
    renderer->Render(*this);
}
