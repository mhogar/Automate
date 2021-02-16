#include "VulkanWindow.h"

VulkanWindow::VulkanWindow() {
    mRenderer = new VulkanRenderer();
    mWindow = nullptr;

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

VulkanWindow::~VulkanWindow() {
    delete mRenderer;

    DestroyWindow();
    glfwTerminate();
}

void VulkanWindow::CreateWindow(int width, int height, const char* title) {
    mWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);

    // setup callback to notify the renderer when the window is resized
    glfwSetWindowUserPointer(mWindow, mRenderer);
    glfwSetFramebufferSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
        VulkanRenderer* renderer = reinterpret_cast<VulkanRenderer*>(glfwGetWindowUserPointer(window));
        renderer->NotifyFrameBufferResized();
    });
}

void VulkanWindow::DestroyWindow() {
    if (mWindow == nullptr) {
        return;
    }

    glfwDestroyWindow(mWindow);
    mWindow = nullptr;
}

bool VulkanWindow::ShouldClose() {
    return glfwWindowShouldClose(mWindow);
}

void VulkanWindow::PollEvents() {
    glfwPollEvents();
}
