#include "Animation.h"
#include <list>

class AnimationRenderer {
    public:
        void RenderAnimation(Animation animation);
        
    private:
        void ResolveActions();
        void RenderFrame();

        std::list<Action*> mActiveActions;
};
