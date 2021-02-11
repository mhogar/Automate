#include "GraphicsImpl.h"

GraphicsImpl* GraphicsImplFactory::mInstance = nullptr;

GraphicsImpl* GraphicsImplFactory::GetGraphicsImpl() {
    if (mInstance == nullptr) {
        mInstance = CreateGraphicsImpl();
    }

    return mInstance;
}
