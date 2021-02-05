#include "Animation.h"
#include <list>

class AnimationRenderer {
    public:
        static void RenderAnimation(Animation animation);
        
    private:
        static void ResolveActions();
        static void RenderFrame();

        static std::list<Action*> mActiveActions;
};
