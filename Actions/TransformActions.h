#pragma once

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

class TranslateAction : public TransformAction<glm::vec3> {
    public:
        TranslateAction(glm::vec3* data, glm::vec3 endValue, float duration);
};

class RotateAction : public TransformAction<glm::vec3> {
    public:
        RotateAction(glm::vec3* data, glm::vec3 endValue, float duration);
};

class ScaleAction : public TransformAction<glm::vec3> {
    public:
        ScaleAction(glm::vec3* data, glm::vec3 endValue, float duration);
};

class OpacityAction : public TransformAction<float> {
    public:
        OpacityAction(float* data, float endValue, float duration);
};
