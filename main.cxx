#include "Animation/AnimationRenderer.h"
#include "Animation/AnimationParser.h"

void AnimationSrc(AnimationBuilder*);

int main() {
    std::shared_ptr<Animation> animation = AnimationParser::ParseFromCode(30, AnimationSrc);
    AnimationRenderer::RenderAnimation(*animation);
}

void AnimationSrc(AnimationBuilder* b) {
    b->Translate(2);
    b->Delay(1);
    b->Opacity(1);
}
