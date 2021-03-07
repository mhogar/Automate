#ifndef ACTIONS_ACTION_H
#define ACTIONS_ACTION_H

class Action {
    public:
        virtual ~Action() {}

        virtual void Initialize() {}
        virtual void Execute() {}
        virtual bool IsResolved() const = 0;

        bool IsHalting() const;

    protected:
        bool mIsHalting;
};

class TimedAction : public Action {
    public:
        TimedAction(float duration);

        virtual void Initialize();
        virtual void Execute();
        virtual bool IsResolved() const;

    protected:
        float mCurrentFrame;
        float mDuration;
};

#endif
