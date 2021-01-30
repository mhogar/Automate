class Directive {
    public:
        virtual ~Directive() {}
        virtual bool Execute() = 0;
};

class TimedDir : public Directive{
    public:
        TimedDir(int numFrames);
        virtual bool Execute();

    protected:
        int _currentFrame;
        int _numFrames;
};

class TranslateYDir : public TimedDir {
    public:
        TranslateYDir(int numFrames);
        virtual bool Execute();
};

class OpacityDir : public TimedDir {
    public:
        OpacityDir(int numFrames);
        virtual bool Execute();
};
