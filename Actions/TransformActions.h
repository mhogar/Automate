#ifndef ACTIONS_TRANSFORM_ACTION_H
#define ACTIONS_TRANSFORM_ACTION_H

#include "Action.h"
#include "Actors/ActorData.hxx"

template <class T>
class TransformAction : public AnimateAction {
    public:
        TransformAction(T* data, T endValue, float duration);
        
        virtual void Initialize();
        virtual void Execute(float dt);
        virtual bool IsResolved() const;

    protected:
        float mTimer;
        float mDuration;

        T mStartValue;
        T mEndValue;
        T* mData;
};

class TranslateAction : public TransformAction<glm::vec2> {
    public:
        TranslateAction(glm::vec2* data, glm::vec2 endPos, float duration);
};

class OpacityAction : public TransformAction<float> {
    public:
        OpacityAction(float* data, float endOpacity, float duration);
};

#endif
