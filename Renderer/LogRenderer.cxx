#include "LogRenderer.h"

LogRenderer::LogRenderer(std::ostream& stream) 
    : mStream(stream) {}

void LogRenderer::Render(const BoxActor& box) {
    mStream << "Render box: ";
    mStream << "(" << box.Position.x << ", " << box.Position.y << ", " << box.Position.z << ") ";
    mStream << "(" << box.Rotation.x << ", " << box.Rotation.y << ", " << box.Rotation.z << ") ";
    mStream << "(" << box.Scale.x << ", " << box.Scale.y << ", " << box.Scale.z <<") ";
    mStream << box.Opacity * 100 << "%" << std::endl;
}
