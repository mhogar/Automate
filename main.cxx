#include "AnimationRenderer.h"
#include "Animation/AnimationBuilder.h"

Animation BuildAnimation();

int main() {
    AnimationRenderer renderer;
    renderer.RenderAnimation(BuildAnimation());
}

Animation BuildAnimation() {
    AnimationBuilder builder = AnimationBuilder(30);

    builder.Translate(2);
    builder.Delay(1);
    builder.Opacity(1);
    
    return builder.FinalizeAnimation();
}
