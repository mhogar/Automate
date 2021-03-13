#pragma once

#include "ActorAnimator.h"

class Animation {
    public:
        ActorAnimator GetRoot();
        void Render(float framerate);

    private:
        Actor mRoot;
};
