#ifndef ANIMATION_ANIMATION_H
#define ANIMATION_ANIMATION_H

#include "ActorAnimator.h"

class Animation {
    public:
        ActorAnimator GetRoot();
        void Render(float framerate);

    private:
        Actor mRoot;
};

#endif
