#include "LogRenderer.h"

LogRenderer::LogRenderer(std::ostream& stream) 
    : mStream(stream) {}

void LogRenderer::Render(const BoxActor& box) {
    BoxData data = *box.GetBoxData();

    mStream << "Render box: ";
    mStream << "(" << data.Position.x << ", " << data.Position.y << ", " << data.Position.z << ") ";
    mStream << "(" << data.Rotation.x << ", " << data.Rotation.y << ", " << data.Rotation.z << ") ";
    mStream << "(" << data.Scale.x << ", " << data.Scale.y << ", " << data.Scale.z <<") ";
    mStream << data.Opacity * 100 << "%" << std::endl;
}
