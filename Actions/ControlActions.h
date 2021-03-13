#ifndef ACTIONS_STD_ACTION_H
#define ACTIONS_STD_ACTION_H

#include "Action.h"
#include "Timeline.h"

class DelayAction : public ControlAction {
    public:
        DelayAction(float duration);

        virtual void Initialize();
        virtual void Execute(float dt);
        virtual bool IsResolved() const;

    protected:
        float mTimer;
        float mDuration;
};

class WaitAction : public ControlAction {
    public:
        WaitAction(const Timeline* timeline);
        virtual bool IsResolved() const;
    
    protected:
        const Timeline* mTimeline;
};

// class RunAsyncAnimationAction : public Action {
//     public:
//         RunAsyncAnimationAction(Animation* parent, std::shared_ptr<Animation> animation);
//         virtual void Initialize();
//         virtual bool IsResolved() const;

//     protected:
//         Animation* mParent;
//         std::shared_ptr<Animation> mAnimation;
// };

// class RunAnimationAction : public RunAsyncAnimationAction {
//     public:
//         RunAnimationAction(Animation* parent, std::shared_ptr<Animation> animation);
//         virtual bool IsResolved() const;
// };

#endif
