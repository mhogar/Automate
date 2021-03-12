#ifndef ANIMATION_ANIMATION_H
#define ANIMATION_ANIMATION_H

#include "RootAnimator.h"

class Animation {
    public:
        Animation();
        ~Animation();

        RootAnimator GetRoot();

        void Render();

    private:
        RootActor* mRoot;
};

#endif
