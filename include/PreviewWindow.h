#pragma once

#include <thread>
#include <optional>

class PreviewWindow {
    public:
        PreviewWindow();
        virtual ~PreviewWindow();

        void Open(int width, int height, const char* title);
        void Close();

        bool IsOpen() const;

    protected:
        virtual void CreateWindow(int width, int height, const char* title) = 0;
        virtual void DestroyWindow() = 0;

        virtual void Update() = 0;

        bool mShouldQuit;

    private:
        std::optional<std::thread> mThread;
        bool mWindowOpen;
};
