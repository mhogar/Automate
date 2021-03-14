#include "Animation.h"

void CreateAnimation(ActorAnimator& root);

int main() {
    Animation animation;
    ActorAnimator root = animation.GetRoot();
    
    CreateAnimation(root);

    animation.LogRender(10);
}

void CreateAnimation(ActorAnimator& root) {
    BoxData boxData;
    ActorAnimator box = root.AddBoxChild(boxData);

    box.Translate(50, 50, 1);
    box.Rotate(45, 1);
    box.Scale(50, 50, 1);
    box.Opacity(0, 1);
}
