#pragma once

#include "ActorAnimator.h"

class Animation {
    public:
        ActorAnimator GetRoot();
        void LogRender(float framerate);

    private:
        Actor mRoot;
};
