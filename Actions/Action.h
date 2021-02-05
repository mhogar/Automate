class Action {
    public:
        virtual ~Action() {}
        virtual void Initialize() {}
        virtual void Execute() {}
        virtual bool IsResolved() = 0;

        bool IsHalting();
    protected:
        bool mIsHalting = false;
};

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
