#ifndef ANIMATION_ANIMATION_PARSER_H
#define ANIMATION_ANIMATION_PARSER_H

#include "AnimationBuilder.h"
#include <functional>

class AnimationParser {
    public:
        static std::shared_ptr<Animation> ParseFromCode(int framerate, std::function<void(AnimationBuilder*)> codeFunc);
};

#endif
