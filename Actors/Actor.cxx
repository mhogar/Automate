#include "Actor.h"
#include "Actions/TransformActions.h"

Actor::Actor() : Actor(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f) {
}

Actor::Actor(float posX, float posY, float rot, float scaleX, float scaleY, float opacity) {
    mPosition.x = posX;
    mPosition.y = posY;
    
    mRotation = rot;

    mScale.x = scaleX;
    mScale.y = scaleY;

    mOpacity = opacity;
}

void Actor::Translate(float duration) {
    mActions.push_back(new TranslateAction(this, duration));
}

void Actor::Opacity(float duration) {
    mActions.push_back(new OpacityAction(this, duration));
}
