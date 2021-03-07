#ifndef ACTORS_ROOT_ACTOR_H
#define ACTORS_ROOT_ACTOR_H

#include "Actions/Action.h"
#include "Actor.h"
#include <list>
#include <vector>

class Action;
class Actor;

class RootActor {
    public:
        ~RootActor();

        void Initialize();

        void AddChildActor(Actor* child);

        int GetNumActiveActions() const;
        bool IsAnimationComplete() const;

        void Update();
        void Render();

        void Delay(float duration);
        void Wait();

    protected:
        std::vector<Action*> mActions;

    private:
        void UpdateActiveActions();
        void ResolveActiveActions();

        std::list<Actor*> mChildActors;

        std::list<Action*> mActiveActions;
        int mNextActionIndex;

        bool mIsHalted;
};

#endif
