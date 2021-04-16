#pragma once

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
