#include "Actions/Action.h"
#include <list>

class Animation {
    public:
        Animation();

        void AddAction(Action* action);
        void AddChildAnimation(Animation child);

        std::list<Action*> GetNextActions();
        bool IsAnimationComplete();
        bool IsAnimationAndChildrenComplete();
    private:
        std::list<Animation> mChildAnimations;

        std::list<Action*> mActions;
        std::list<Action*>::iterator mActionItr;
        bool mIsHalted;
};
