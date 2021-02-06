#ifndef ANIMATION_ANIMATION_H
#define ANIMATION_ANIMATION_H

#include "Actions/Action.h"
#include <list>

class Action;

class Animation {
    public:
        Animation() {};
        ~Animation();

        void Initialize();

        void AddAction(Action* action);
        void AddChildAnimation(Animation* child);

        int GetNumActiveActions() const;
        bool IsAnimationComplete() const;

        void NotifyActionResolved();
        std::list<Action*> GetNextActions();

    private:
        std::list<Animation*> mChildAnimations;

        std::list<Action*> mActions;
        std::list<Action*>::iterator mActionItr;

        int mNumActiveActions;
        bool mIsHalted;
        
};

#endif
