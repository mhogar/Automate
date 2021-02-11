#ifndef ACTIONS_TRANSFORM_ACTION_H
#define ACTIONS_TRANSFORM_ACTION_H

#include "Action.h"

class TranslateAction : public TimedAction {
    public:
        TranslateAction(const Animation* parent, int duration);
        virtual void Execute();
};

class OpacityAction : public TimedAction {
    public:
        OpacityAction(const Animation* parent, int duration);
        virtual void Execute();
};

#endif
