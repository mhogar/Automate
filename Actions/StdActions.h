#ifndef ACTIONS_STD_ACTION_H
#define ACTIONS_STD_ACTION_H

#include "Action.h"
#include <memory>

class DelayAction : public TimedAction {
    public:
        DelayAction(const Animation* parent, int duration);
};

class WaitAction : public Action {
    public:
        WaitAction(const Animation* parent);
        virtual bool IsResolved() const;
    
    protected:
        const Animation* mParent;
};

class RunAsyncAnimationAction : public Action {
    public:
        RunAsyncAnimationAction(Animation* parent, std::shared_ptr<Animation> animation);
        virtual void Initialize();
        virtual bool IsResolved() const;

    protected:
        Animation* mParent;
        std::shared_ptr<Animation> mAnimation;
};

class RunAnimationAction : public RunAsyncAnimationAction {
    public:
        RunAnimationAction(Animation* parent, std::shared_ptr<Animation> animation);
        virtual bool IsResolved() const;
};

#endif
