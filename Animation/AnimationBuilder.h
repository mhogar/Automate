#include "Animation.h"
#include <memory>

class AnimationBuilder {
    public: 
        AnimationBuilder(int framerate);
        std::shared_ptr<Animation> GetAnimation() const;

        void Delay(int duration);
        void Wait();

        void RunAnimation(Animation* animation);
        void RunAsyncAnimation(Animation* animation);

        void Translate(int duration);
        void Opacity(int duration);

    private:
        std::shared_ptr<Animation> mAnimation;
        int mFramerate;
};
