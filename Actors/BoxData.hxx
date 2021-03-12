#ifndef ACTORS_BOX_DATA_H
#define ACTORS_BOX_DATA_H

#include "ActorData.hxx"

struct BoxData : public ActorData {
    const char* mColour;

    BoxData() {
        mColour = "red";
    }
};

#endif
