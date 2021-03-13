#pragma once

#include "Action.h"
#include <vector>
#include <list>

class Timeline {
    public:
        Timeline();
        ~Timeline();

        void Reset();
        
        void AddAction(Action* action);

        int GetNumActiveActions() const;
        bool IsTimelineComplete() const;

        void Update(float dt);
        void Render();

    protected:
        std::vector<Action*> mActions;

    private:
        void UpdateActiveActions();
        void ResolveActiveActions(float dt);

        std::list<Action*> mActiveActions;
        int mNextActionIndex;

        bool mIsHalted;
};
