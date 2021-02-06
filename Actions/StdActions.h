#ifndef ACTIONS_STD_ACTION_H
#define ACTIONS_STD_ACTION_H

#include "Action.h"
#include <memory>

class DelayAction : public TimedAction {
    public:
        DelayAction(Animation* parent, int duration);
};

class WaitAction : public Action {
    public:
        WaitAction(Animation* parent);
        virtual bool IsResolved();
};

class RunAsyncAnimationAction : public Action {
    public:
        RunAsyncAnimationAction(Animation* parent, std::shared_ptr<Animation> animation);
        virtual void Initialize();
        virtual bool IsResolved();

    protected:
        std::shared_ptr<Animation> mAnimation;
};

class RunAnimationAction : public RunAsyncAnimationAction {
    public:
        RunAnimationAction(Animation* parent, std::shared_ptr<Animation> animation);
        virtual bool IsResolved();
};

#endif
