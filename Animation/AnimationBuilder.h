#include "Animation.h"

class AnimationBuilder {
    public: 
        AnimationBuilder(int framerate);
        Animation FinalizeAnimation();

        void Delay(int duration);
        void Wait();

        void RunAnimation(Animation animation);
        void RunAsyncAnimation(Animation animation);

        void Translate(int duration);
        void Opacity(int duration);

    private:
        Animation mAnimation;
        int mFramerate;
};
