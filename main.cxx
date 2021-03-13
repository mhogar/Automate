#include "Animation/Animation.h"

void CreateAnimation(ActorAnimator& root);

int main() {
    Animation animation;
    ActorAnimator root = animation.GetRoot();
    
    CreateAnimation(root);

    animation.Render(10);
}

void CreateAnimation(ActorAnimator& root) {
    BoxData boxData;
    ActorAnimator box = root.AddBoxChild(boxData);

    box.Translate(50, 50, 1.0f);
    root.Delay(0.5f);
    box.Opacity(0.1f, 1.0f);
}
