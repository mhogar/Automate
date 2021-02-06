#ifndef ACTIONS_TRANSFORM_ACTION_H
#define ACTIONS_TRANSFORM_ACTION_H

#include "Action.h"

class TranslateAction : public TimedAction {
    public:
        TranslateAction(int durationFrames);
        virtual void Execute();
};

class OpacityAction : public TimedAction {
    public:
        OpacityAction(int numFrames);
        virtual void Execute();
};

#endif
