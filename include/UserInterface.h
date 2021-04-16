#pragma once

class UserInterface {
    public:
        virtual void MainLoop() = 0;
        static UserInterface* CreateInstance();
};
