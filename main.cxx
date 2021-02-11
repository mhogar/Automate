#include "Animation/PreviewHandle.h"
#include "Animation/AnimationBuilder.h"

std::shared_ptr<Animation> RootAnimation();
std::shared_ptr<Animation> ChildAnimation();

int main() {
    std::shared_ptr<Animation> animation = RootAnimation();

    PreviewHandle preivew;
    preivew.PreviewAnimation(*animation, 10);
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
