#ifndef ANIMATION_ANIMATION_RENDERER_H
#define ANIMATION_ANIMATION_RENDERER_H

#include "Actors/RootActor.h"
#include <list>

class AnimationRenderer {
    public:
        static void RenderAnimation(RootActor& root);

        static void Initialize(int framerate);
        
        static void ConfigureFrameRate(int framerate);
        static int GetFrameRate();
        
    private:
        static int mFrameRate;
};

#endif
