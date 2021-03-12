#ifndef ACTIONS_TIMELINE_H
#define ACTIONS_TIMELINE_H

#include "Action.h"
#include <vector>
#include <list>

class Timeline {
    public:
        ~Timeline();

        void Reset();
        
        void AddAction(Action* action);

        int GetNumActiveActions() const;
        bool IsTimelineComplete() const;

        void Update();
        void Render();

    protected:
        std::vector<Action*> mActions;

    private:
        void UpdateActiveActions();
        void ResolveActiveActions();

        std::list<Action*> mActiveActions;
        int mNextActionIndex;

        bool mIsHalted;
};

#endif
