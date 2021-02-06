#include "Animation.h"

Animation::~Animation() {
    for (Action* action : mActions) {
        delete action;
    }
}

void Animation::Initialize() {
    mActionItr = mActions.begin();
    mNumActiveActions = 0;
    mIsHalted = false;
    mChildAnimations.clear();
}

void Animation::AddAction(Action* action) {
    mActions.push_back(action);
}

void Animation::AddChildAnimation(Animation* child) {
    mChildAnimations.push_back(child);
}

void Animation::NotifyActionResolved() {
    mNumActiveActions--;
}

int Animation::GetNumActiveActions() const {
    return mNumActiveActions;
}

bool Animation::IsAnimationComplete() const {
    if (mActionItr != mActions.end() || mNumActiveActions > 0) {
        return false;
    }

    for (Animation* child : mChildAnimations) {
        if (!child->IsAnimationComplete()) {
            return false;
        }
    }
    
    return true;
}

std::list<Action*> Animation::GetNextActions() {
    std::list<Action*> actions;

    while (mActionItr != mActions.end()) {
        Action* action = *mActionItr;

        if (mIsHalted) {
            if (!action->IsResolved()) {
                break;
            }
            
            mIsHalted = false;
            mActionItr++;
            continue;
        }

        action->Initialize();
        actions.push_back(action);
        mNumActiveActions++;

        if (action->IsHalting()) {
            mIsHalted = true;
            break;
        }

        mActionItr++;
    }

    for (Animation* child : mChildAnimations) {
        actions.splice(actions.end(), child->GetNextActions());
    }

    return actions;
}
