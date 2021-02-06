#ifndef ACTIONS_STD_ACTION_H
#define ACTIONS_STD_ACTION_H

#include "Action.h"
#include "Animation/Animation.h"

class DelayAction : public TimedAction {
    public:
        DelayAction(int durationFrames);
};

class WaitAction : public Action {
    public:
        WaitAction(const Animation* parent);
        virtual bool IsResolved();
    
    protected:
        const Animation* mParent;
};

class RunAsyncAnimationAction : public Action {
    public:
        RunAsyncAnimationAction(Animation* parent, Animation* animation);
        virtual void Initialize();
        virtual bool IsResolved();

    protected:
        Animation* mParent;
        Animation* mAnimation;
};

class RunAnimationAction : public RunAsyncAnimationAction {
    public:
        RunAnimationAction(Animation* parent, Animation* animation);
        virtual bool IsResolved();
};

#endif
