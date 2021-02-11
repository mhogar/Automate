#ifndef ANIMATION_ANIMATION_H
#define ANIMATION_ANIMATION_H

#include "Actions/Action.h"
#include <list>
#include <vector>

class Action;

class Animation {
    public:
        ~Animation();

        void Initialize(int framerate);

        void AddAction(Action* action);
        void AddChildAnimation(Animation* child);

        int GetNumActiveActions() const;
        int GetFrameRate() const;
        bool IsComplete() const;

        void Update();
        void Render();

    private:
        void UpdateActiveActions();
        void ResolveActiveActions();

        std::list<Animation*> mChildAnimations;

        std::vector<Action*> mActions;
        std::list<Action*> mActiveActions;
        int mNextActionIndex;

        bool mIsHalted;
        int mFrameRate;
};

#endif
