#include "Animation.h"
#include <unordered_set>

class AnimationRenderer {
    public:
        AnimationRenderer();

        void Render();

    private:
        void RenderAnimation(Animation animation);
        void RenderFrame();

        std::list<Animation> mAnimations;
        std::unordered_set<Action*> mActiveActions;
};
