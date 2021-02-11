#ifndef ANIMATION_ANIMATION_BUILDER_H
#define ANIMATION_ANIMATION_BUILDER_H

#include "Animation.h"
#include <memory>

class AnimationBuilder {
    public: 
        AnimationBuilder();
        std::shared_ptr<Animation> GetAnimation() const;

        void Delay(int duration);
        void Wait();

        void Run(std::shared_ptr<Animation> animation);
        void RunAsync(std::shared_ptr<Animation> animation);

        void Translate(int duration);
        void Opacity(int duration);

    private:
        std::shared_ptr<Animation> mAnimation;
        int mFrameRate;
};

#endif
