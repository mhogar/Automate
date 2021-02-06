#ifndef ACTIONS_ACTION_H
#define ACTIONS_ACTION_H

#include "Animation/Animation.h"

class Animation;

class Action {
    public:
        Action(Animation* parent);
        virtual ~Action() {}

        virtual void Initialize() {}
        virtual void Execute() {}
        virtual bool IsResolved() = 0;

        bool IsHalting();
        void NotifyParentActionResolved();

    protected:
        Animation* mParent;
        bool mIsHalting;
};

class TimedAction : public Action{
    public:
        TimedAction(Animation* parent, int duration);

        virtual void Initialize();
        virtual void Execute();
        virtual bool IsResolved();

    protected:
        int mCurrentFrame;
        int mDuration;
};

#endif
