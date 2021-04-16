#include "Action.h"

Action::Action() {
    mIsHalting = false;
}

bool Action::IsHalting() const {
    return mIsHalting;
}
