#include "Animation.h"
#include <list>

class AnimationRenderer {
    public:
        AnimationRenderer();

        void Render(Animation animation);

    private:
        void ResolveActions();
        void RenderFrame();

        std::list<Action*> mActiveActions;
};
