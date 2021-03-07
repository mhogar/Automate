#include "BoxActor.h"

BoxActor::BoxActor() {
    mColour = "red";
}

BoxActor::BoxActor(float posX, float posY, float rot, float scaleX, float scaleY, float opacity, const char* colour)
    : Actor(posX, posY, rot, scaleX, scaleY, opacity)
{
    mColour = colour;
}

void BoxActor::RenderActor() {
}
