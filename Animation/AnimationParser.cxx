#include "AnimationParser.h"

std::shared_ptr<Animation> AnimationParser::ParseFromCode(int framerate, std::function<void(AnimationBuilder*)> codeFunc) {
    AnimationBuilder builder = AnimationBuilder(framerate);
    codeFunc(&builder);    
    return builder.GetAnimation();
}
