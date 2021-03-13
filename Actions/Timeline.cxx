#include "Timeline.h"

Timeline::Timeline() {
    Reset();
}

Timeline::~Timeline() {
    for (Action* action : mActions) {
        delete action;
    }
}

void Timeline::Reset() {
    mNextActionIndex = 0;
    mIsHalted = false;
    mActiveActions.clear();
}

void Timeline::AddAction(Action* action) {
    mActions.push_back(action);
}

int Timeline::GetNumActiveActions() const {
    return mActiveActions.size();
}

bool Timeline::IsTimelineComplete() const {
    return mNextActionIndex >= mActions.size() && mActiveActions.empty();
}

void Timeline::Update(float dt) {
    UpdateActiveActions();
    ResolveActiveActions(dt);
}

void Timeline::UpdateActiveActions() {
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

void Timeline::ResolveActiveActions(float dt) {
    std::list<Action*> resolvedActions;

    for (Action* action : mActiveActions) {
        action->Execute(dt);

        if (action->IsResolved()) {
            resolvedActions.push_back(action);
        }
    }

    for (Action* action : resolvedActions) {
        mActiveActions.remove(action);
    }
}
