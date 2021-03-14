#pragma once

#include "Renderer.h"
#include <iostream>

class LogRenderer : public Renderer {
    public:
        LogRenderer(std::ostream& stream);
        virtual void Render(const BoxActor& box);

    private:
        std::ostream& mStream;
};
