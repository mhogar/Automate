#pragma once

class Action {
    public:
        virtual ~Action() {}

        virtual void Initialize() {}
        virtual void Execute(float dt) {}
        virtual bool IsResolved() const = 0;

        bool IsHalting() const;

    protected:
        bool mIsHalting;
};

class ControlAction : public Action {
    public:
        virtual ~ControlAction() {}
};

class AnimateAction : public Action {
    public:
        virtual ~AnimateAction() {}
};
