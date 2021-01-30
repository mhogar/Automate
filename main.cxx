#include "Animation.h"

int main() {
    Animation anim = Animation(15);

    anim.TranslateY(2);
    anim.Delay(1);
    anim.Opacity(1);
    anim.Wait();
}
