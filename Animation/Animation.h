#include "Actions/Action.h"
#include <list>

class Animation {
    public:
        Animation();
        Animation(int framerate);

        //void Wait();
        void Delay(int duration);

        void Translate(int duration);
        void Opacity(int duration);

        void AddChildAnimation(Animation child);

        std::list<Action*> GetNextActions();
        bool IsAnimationComplete();
        bool IsAnimationAndChildrenComplete();
    private:
        std::list<Animation> mChildAnimations;

        std::list<Action*> mActions;
        std::list<Action*>::iterator mActionItr;
        bool mIsHalted;

        int mFramerate;
};
