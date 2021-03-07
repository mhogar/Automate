#ifndef ACTORS_ROOT_ACTOR_H
#define ACTORS_ROOT_ACTOR_H

#include "Actions/Action.h"
#include <list>
#include <vector>

class RootActor {
    public:
        ~RootActor();

        void Initialize();

        void AddChildActor(RootActor* child);

        int GetNumActiveActions() const;
        bool IsAnimationComplete() const;

        void Update();
        void Render();

        virtual void RenderActor() = 0;

        void Delay(float duration);
        void Wait();

    protected:
        std::vector<Action*> mActions;

    private:
        void UpdateActiveActions();
        void ResolveActiveActions();

        std::list<RootActor*> mChildActors;

        std::list<Action*> mActiveActions;
        int mNextActionIndex;

        bool mIsHalted;
};

#endif
