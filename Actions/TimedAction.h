#include "Action.h"

class TimedAction : public Action{
    public:
        TimedAction(int durationFrames);

        virtual void Initialize();
        virtual void Execute();
        virtual bool IsResolved();

    protected:
        int mCurrentFrame;
        int mDurationFrames;
};
