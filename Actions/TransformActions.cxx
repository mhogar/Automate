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

    std::cout << "Transform " << mTimer << std::endl;
}

template <class T>
bool TransformAction<T>::IsResolved() const {
    return mTimer >= mDuration;
}

//--------------------------------------------------------------------------------

TranslateAction::TranslateAction(glm::vec2* data, glm::vec2 endPos, float duration)
    : TransformAction(data, endPos, duration) {}

OpacityAction::OpacityAction(float* data, float endOpacity, float duration)
    : TransformAction(data, endOpacity, duration) {}
