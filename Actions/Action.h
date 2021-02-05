class Action {
    public:
        virtual ~Action() {}
        virtual void Initialize() {}
        virtual void Execute() {}
        virtual bool IsResolved() = 0;

        bool IsHalting() { return mIsHalting; }
    protected:
        bool mIsHalting = false;
};
