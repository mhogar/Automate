#include "AnimationRenderer.h"
#include "Animation/AnimationParser.h"

void AnimationSrc(AnimationBuilder*);

int main() {
    AnimationRenderer::RenderAnimation(
        AnimationParser::ParseFromCode(30, AnimationSrc)
    );
}

void AnimationSrc(AnimationBuilder* b) {
    b->Translate(2);
    b->Delay(1);
    b->Opacity(1);
}
