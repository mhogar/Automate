#include "Animation.h"

ActorAnimator Animation::GetRoot() {
    return ActorAnimator(&mRoot);
}

void Animation::Render(float framerate) {
    float dt = 1.0f / framerate;

    while (!mRoot.GetTimelineRef()->IsTimelineComplete()) {
        mRoot.Update(dt);
        mRoot.Render();
    }
}
