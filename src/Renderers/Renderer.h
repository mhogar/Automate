#pragma once

#include "Actors/BoxActor.h"

class Renderer {
    public:
        virtual void Render(const BoxActor& box) = 0;
};
