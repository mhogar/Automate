#include "TransformActions.h"
#include <iostream>

template <class T>
TransformAction<T>::TransformAction(T* data, T endValue, float duration) {
    mData = data;
    mEndValue = endValue;
    mDuration = duration;
}

template <class T>
void TransformAction<T>::Initialize() {
    mTimer = 0;
    mStartValue = *mData;
}

template <class T>
void TransformAction<T>::Execute(float dt) {
    mTimer += dt;
    if (mTimer > mDuration) {
        mTimer = mDuration;
    }

    *mData = mStartValue + (mTimer / mDuration) * (mEndValue - mStartValue);
}

template <class T>
bool TransformAction<T>::IsResolved() const {
    return mTimer >= mDuration;
}

//--------------------------------------------------------------------------------

TranslateAction::TranslateAction(glm::vec3* data, glm::vec3 endValue, float duration)
    : TransformAction(data, endValue, duration) {}

RotateAction::RotateAction(glm::vec3* data, glm::vec3 endValue, float duration)
    : TransformAction(data, endValue, duration) {}

ScaleAction::ScaleAction(glm::vec3* data, glm::vec3 endValue, float duration)
    : TransformAction(data, endValue, duration) {}

OpacityAction::OpacityAction(float* data, float endValue, float duration)
    : TransformAction(data, endValue, duration) {}
