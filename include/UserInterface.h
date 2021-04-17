#pragma once

class UserInterface {
    public:
        virtual ~UserInterface() {}
        virtual void MainLoop() = 0;
        
        static UserInterface* CreateInstance();
};
