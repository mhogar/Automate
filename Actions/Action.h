#ifndef ACTIONS_ACTION_H
#define ACTIONS_ACTION_H

#include "Animation/Animation.h"

class Animation;

class Action {
    public:
        virtual ~Action() {}

        virtual void Initialize() {}
        virtual void Execute() {}
        virtual bool IsResolved() const = 0;

        bool IsHalting() const;

    protected:
        bool mIsHalting;
};

class TimedAction : public Action {
    public:
        TimedAction(int duration);

        virtual void Initialize();
        virtual void Execute();
        virtual bool IsResolved() const;

    protected:
        int mCurrentFrame;
        int mDuration;
};

#endif
