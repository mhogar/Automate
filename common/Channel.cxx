#include "Channel.h"

template <class T>
Channel<T>::Channel() {
    mHasData = false;
}

template <class T>
bool Channel<T>::HasData() {
    return mHasData;
}

template <class T>
void Channel<T>::PushData(T data) {
    mMutex.lock();
    {
        mBuffer.push(data);
        mHasData = true;
    }
    mMutex.unlock();
}

template <class T>
std::vector<T> Channel<T>::PopData() {
    std::vector<T> data;

    mMutex.lock();
    {
        data.reserve(mBuffer.size());
        for (int i = 0; i < data.size(); i++) {
            data[i] = mBuffer.front();
            mBuffer.pop();
        }

        mHasData = false;
    }
    mMutex.unlock();

    return data;
}
