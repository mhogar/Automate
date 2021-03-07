#include "RootActor.h"
#include "Actions/StdActions.h"

RootActor::~RootActor() {
    for (Action* action : mActions) {
        delete action;
    }
}

void RootActor::Initialize() {
    mNextActionIndex = 0;
    mIsHalted = false;

    mChildActors.clear();
    mActiveActions.clear();
}

void RootActor::AddChildActor(Actor* child) {
    mChildActors.push_back(child);
}

int RootActor::GetNumActiveActions() const {
    return mActiveActions.size();
}

bool RootActor::IsAnimationComplete() const {
    if (mNextActionIndex < mActions.size() || mActiveActions.size() > 0) {
        return false;
    }

    for (Actor* child : mChildActors) {
        if (!child->IsAnimationComplete()) {
            return false;
        }
    }
    
    return true;
}

void RootActor::Update() {
    UpdateActiveActions();
    ResolveActiveActions();

    for (Actor* child : mChildActors) {
        child->Update();
    }
}

void RootActor::Render() {
    
}

void RootActor::UpdateActiveActions() {
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

void RootActor::ResolveActiveActions() {
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


void RootActor::Delay(float duration) {
    mActions.push_back(new DelayAction(duration));
}

void RootActor::Wait() {
    mActions.push_back(new WaitAction(this));
}
