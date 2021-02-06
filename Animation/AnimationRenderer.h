#ifndef ANIMATION_ANIMATION_RENDERER_H
#define ANIMATION_ANIMATION_RENDERER_H

#include "Animation.h"
#include <list>

class AnimationRenderer {
    public:
        static void RenderAnimation(Animation& animation);

        static void ConfigureFrameRate(int framerate);
        static int GetFrameRate();
        
    private:
        static void ResolveActions(Animation& animation);
        static void RenderFrame();

        static std::list<Action*> mActiveActions;
        static int mFrameRate;
};

#endif
