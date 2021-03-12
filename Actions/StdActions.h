#ifndef ACTIONS_STD_ACTION_H
#define ACTIONS_STD_ACTION_H

#include "Action.h"
#include "Actors/RootActor.h"
#include <memory>

class DelayAction : public TimedAction {
    public:
        DelayAction(float duration);
};

class WaitAction : public Action {
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
