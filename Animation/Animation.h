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

        Action* GetAction();
        void NextAction();
        bool HasNextAction();
    private:
        std::list<Action*> mActions;
        std::list<Action*>::iterator mActionItr;

        int mFramerate;
};
