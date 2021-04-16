#include "UserInterface.h"

int main() {
    UserInterface* ui = UserInterface::CreateInstance();
    ui->MainLoop();
    delete ui;
}
