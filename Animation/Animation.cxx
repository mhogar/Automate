#include "Animation.h"
#include "Actions/StdActions.h"
#include "Actions/TransformActions.h"
#include <iostream>

Animation::Animation() {
    Reset();
}

Animation::~Animation() {
    std::cout << "Delete Animation" << std::endl;
    for (Action* action : mActions) {
        delete action;
    }
}

void Animation::Reset() {
    mActionItr = mActions.begin();
    mNumActiveActions = 1;
    mIsHalted = false;

    for (Animation* child : mChildAnimations) {
        child->Reset();
    }
    mChildAnimations.clear();
}

void Animation::AddAction(Action* action) {
    mActions.push_back(action);
}

void Animation::AddChildAnimation(Animation* child) {
    mChildAnimations.push_back(child);
}

void Animation::NotifyActionResolved(Action* action) {
    // double check action is actually resolved
    if (!action->IsResolved()) {
        return;
    }

    mNumActiveActions--;
}

bool Animation::HasActiveActions() const {
    return mNumActiveActions > 0;
}

bool Animation::IsAnimationComplete() const {
    if (mActionItr != mActions.end() || HasActiveActions()) {
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

        if (mIsHalted && !action->IsResolved()) {
            break;
        }
        mIsHalted = false;

        action->Initialize();
        actions.push_back(action);

        if (action->IsHalting()) {
            mIsHalted = true;
            break;
        }

        mActionItr++;
        mNumActiveActions++;
    }

    for (Animation* child : mChildAnimations) {
        actions.splice(actions.end(), child->GetNextActions());
    }

    return actions;
}
