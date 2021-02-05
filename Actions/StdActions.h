#include "Action.h"
#include "Animation/Animation.h"

class DelayAction : public TimedAction {
    public:
        DelayAction(int durationFrames);
};

class WaitAction : public Action {
    public:
        WaitAction(Animation* parent);
        virtual bool IsResolved();
    
    protected:
        Animation* mParent;
};

class RunAsyncAnimationAction : public Action {
    public:
        RunAsyncAnimationAction(Animation* parent, Animation animation);
        virtual void Initialize();
        virtual bool IsResolved();

    protected:
        Animation* mParent;
        Animation mAnimation;
};

class RunAnimationAction : public RunAsyncAnimationAction {
    public:
        RunAnimationAction(Animation* parent, Animation animation);
        virtual bool IsResolved();
};
