#include "GraphicsFacade.h"

GraphicsFacade* GraphicsFacade::mInstance = nullptr;

GraphicsFacade* GraphicsFacade::Instance() {
    if (mInstance == nullptr) {
        mInstance = CreateInstance();
    }

    return mInstance;
}

void GraphicsFacade::Dispose() {
    if (mInstance != nullptr) {
        delete mInstance;
        mInstance = nullptr;
    }
}
