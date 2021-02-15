#include "VulkanRenderer.h"

VulkanRenderer::VulkanRenderer() {
    mFrameBufferResized = false;
}

void VulkanRenderer::NotifyFrameBufferResized() {
    mFrameBufferResized = true;
}
