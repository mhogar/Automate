#include "Animation.h"

Animation::~Animation() {
    for (Action* action : mActions) {
        delete action;
    }
}

void Animation::Initialize() {
    mNextActionIndex = 0;
    mIsHalted = false;

    mChildAnimations.clear();
    mActiveActions.clear();
}

void Animation::AddAction(Action* action) {
    mActions.push_back(action);
}

void Animation::AddChildAnimation(Animation* child) {
    mChildAnimations.push_back(child);
}

int Animation::GetNumActiveActions() const {
    return mActiveActions.size();
}

bool Animation::IsAnimationComplete() const {
    if (mNextActionIndex < mActions.size() || mActiveActions.size() > 0) {
        return false;
    }

    for (Animation* child : mChildAnimations) {
        if (!child->IsAnimationComplete()) {
            return false;
        }
    }
    
    return true;
}

void Animation::Update() {
    UpdateActiveActions();
    ResolveActiveActions();

    for (Animation* child : mChildAnimations) {
        child->Update();
    }
}

void Animation::Render() {
    
}

void Animation::UpdateActiveActions() {
    while (mNextActionIndex < mActions.size()) {
        Action* action = mActions[mNextActionIndex];

        if (mIsHalted) {
            if (!action->IsResolved()) {
                break;
            }
            
            mIsHalted = false;
            mNextActionIndex++;
            continue;
        }

        action->Initialize();
        mActiveActions.push_back(action);

        if (action->IsHalting()) {
            mIsHalted = true;
            break;
        }

        mNextActionIndex++;
    }
}

void Animation::ResolveActiveActions() {
    std::list<Action*> resolvedActions;

    for (Action* action : mActiveActions) {
        action->Execute();

        if (action->IsResolved()) {
            resolvedActions.push_back(action);
        }
    }

    for (Action* action : resolvedActions) {
        mActiveActions.remove(action);
    }
}
