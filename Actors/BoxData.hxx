#pragma once

#include "ActorData.hxx"

struct BoxData : public ActorData {
    const char* mColour;

    BoxData() {
        mColour = "red";
    }
};
