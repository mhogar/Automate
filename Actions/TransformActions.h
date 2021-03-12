#ifndef ACTIONS_TRANSFORM_ACTION_H
#define ACTIONS_TRANSFORM_ACTION_H

#include "Action.h"
#include "Actors/ActorData.hxx"

class TranslateAction : public TimedAction {
    public:
        TranslateAction(ActorData* data, float duration);
        virtual void Execute();

    private:
        ActorData* mData;
};

class OpacityAction : public TimedAction {
    public:
        OpacityAction(ActorData* data, float duration);
        virtual void Execute();
    
    private:
        ActorData* mData;
};

#endif
