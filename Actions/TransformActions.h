#ifndef ACTIONS_TRANSFORM_ACTION_H
#define ACTIONS_TRANSFORM_ACTION_H

#include "Action.h"
#include "Actors/Actor.h"

class TranslateAction : public TimedAction {
    public:
        TranslateAction(Actor* actor, float duration);
        virtual void Execute();

    private:
        Actor* mActor;
};

class OpacityAction : public TimedAction {
    public:
        OpacityAction(Actor* actor, float duration);
        virtual void Execute();
    
    private:
        Actor* mActor;
};

#endif
