#include "Animation/PreviewHandle.h"
#include "Animation/AnimationBuilder.h"
#include <stdexcept>
#include <iostream>

std::shared_ptr<Animation> RootAnimation();
std::shared_ptr<Animation> ChildAnimation();

int main() {
    std::shared_ptr<Animation> animation = RootAnimation();

    PreviewHandle preivew;
    try {
        preivew.PreviewAnimation(*animation, 10);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
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
