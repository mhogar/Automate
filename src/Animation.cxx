#include "Animation.h"
#include "Actors/Actor.h"
#include "Renderers/LogRenderer.h"

Animation::Animation(){
    mRoot = new Actor();
}

Animation::~Animation() {
    delete mRoot;
}

ActorAnimator Animation::GetRoot() {
    return ActorAnimator(mRoot);
}

void Animation::LogRender(float framerate) {
    float dt = 1.0f / framerate;
    LogRenderer renderer(std::cout);

    while (!mRoot->GetTimelineRef()->IsTimelineComplete()) {
        mRoot->Update(dt);
        mRoot->Render(&renderer);
    }
}
