#include "Animation/AnimationRenderer.h"
#include "Animation/AnimationBuilder.h"

std::shared_ptr<Animation> RootAnimation();
std::shared_ptr<Animation> ChildAnimation();

int main() {
    auto animation = RootAnimation();

    AnimationRenderer::Initialize(10);
    AnimationRenderer::RenderAnimation(*animation);
}

std::shared_ptr<Animation> RootAnimation() {
    AnimationBuilder b;

    b.RunAsync(ChildAnimation());
    b.Translate(1);

    return b.GetAnimation();
}

std::shared_ptr<Animation> ChildAnimation() {
    AnimationBuilder b;

    b.Opacity(2);

    return b.GetAnimation();
}
