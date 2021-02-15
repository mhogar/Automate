#include "GraphicsFactory.h"

std::unique_ptr<GraphicsFactory> GraphicsFactory::mInstance = nullptr;

GraphicsFactory* GraphicsFactory::GetInstance() {
    if (mInstance == nullptr) {
        mInstance = std::unique_ptr<GraphicsFactory>(CreateGraphicsFactory());
    }

    return mInstance.get();
}
