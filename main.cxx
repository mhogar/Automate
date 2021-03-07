#include "Animation/AnimationRenderer.h"
#include "Actors/BoxActor.h"

void FadeIn(Actor* actor);

int main() {
    //RootActor root;
    
    BoxActor box;
    FadeIn(&box);

    AnimationRenderer::Initialize(10);
    AnimationRenderer::RenderAnimation(box);
}

void FadeIn(Actor* actor) {
    actor->Translate(1.0f);
    actor->Wait();
    actor->Opacity(1.0f);
}
