#pragma once

class Window {
    public:
        virtual ~Window() {}

        virtual void PollEvents() = 0;
        virtual bool ShouldClose() = 0;
        virtual void Close() = 0;
};
