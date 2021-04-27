#pragma once

#include <vector>
#include <queue>
#include <mutex>

template <class T>
class Channel {
    public:
        Channel();

        bool HasData();

        void PushData(T data);
        std::vector<T> PopData();

    private:
        bool mHasData;
        std::queue<T> mBuffer;
        std::mutex mMutex;
};
