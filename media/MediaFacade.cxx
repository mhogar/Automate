#include "MediaFacade.h"

MediaFacade* MediaFacade::mInstance = nullptr;

MediaFacade* MediaFacade::Instance() {
    if (mInstance == nullptr) {
        mInstance = CreateInstance();
    }

    return mInstance;
}

void MediaFacade::Dispose() {
    if (mInstance != nullptr) {
        delete mInstance;
        mInstance = nullptr;
    }
}
