#include "Directives/Directive.h"
#include <list>

class Animation {
    public:
        Animation(int framerate);
        ~Animation();

        void Wait();
        void Delay(int duration);

        void TranslateY(int duration);
        void Opacity(int duration);

    private:
        void RenderFrame();

        std::list<Directive*> _directives;

        int _framerate;
        int _currentFrame;
};
