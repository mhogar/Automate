#pragma once

#include "ActorAnimator.h"

class Animation {
    public:
        Animation();
        ~Animation();

        ActorAnimator GetRoot();
        void LogRender(float framerate);

    private:
        Actor* mRoot;
};
