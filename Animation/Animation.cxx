#include "Animation.h"

Animation::Animation() {
    mRoot = new RootActor();
}

Animation::~Animation() {
    delete mRoot;
}

RootAnimator Animation::GetRoot() {
    return RootAnimator(mRoot);
}

void Animation::Render() {
    while (!mRoot->GetTimelineRef()->IsTimelineComplete()) {
        mRoot->Update();
        mRoot->Render();
    }
}
