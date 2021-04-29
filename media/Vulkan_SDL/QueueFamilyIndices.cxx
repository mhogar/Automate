#include "QueueFamilyIndices.h"

bool QueueFamilyIndices::IsComplete() {
    return GraphicsFamily.has_value() && PresentFamily.has_value();
}
