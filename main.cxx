#include "Animation/Animation.h"
#include "Animation/ActorAnimator.h"

void FadeIn(ActorAnimator& actor);

int main() {
    Animation animation;
    RootAnimator root = animation.GetRoot();
    
    BoxData box;
    ActorAnimator boxAnim = root.AddBoxChild(box);

    FadeIn(boxAnim);

    animation.Render();
}

void FadeIn(ActorAnimator& actor) {
    actor.Translate(1.0f);
    actor.Wait();
    actor.Opacity(1.0f);
}
