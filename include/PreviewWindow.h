#pragma once

#include <thread>
#include <optional>

class PreviewWindow {
    public:
        PreviewWindow();
        virtual ~PreviewWindow() {}

        void Open();
        void Close();

        bool IsOpen() const;

    protected:
        virtual void OpenWindow() = 0;
        virtual void CloseWindow() = 0;
        virtual void Update() = 0;

        bool mShouldQuit;

    private:
        std::optional<std::thread> mThread;
        bool mWindowOpen;
};
