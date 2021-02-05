#include "AnimationBuilder.h"
#include <functional>

class AnimationParser {
    public:
        static Animation ParseFromCode(int framerate, std::function<void(AnimationBuilder*)> code);
};