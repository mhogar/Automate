#pragma once

#include "GPUFacade.h"
#include "PreviewWindow.h"

class MediaFacade {
    public:
        virtual ~MediaFacade() {}

        virtual void Init() {}

        virtual GPUFacade* GetGPUFacade() = 0;
        virtual PreviewWindow* CreatePreviewWindow() = 0;

        static MediaFacade* Instance();
        static void Dispose();

    private:
        static MediaFacade* CreateInstance();
        static MediaFacade* mInstance;
};
