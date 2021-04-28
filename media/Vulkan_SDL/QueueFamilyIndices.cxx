#include "QueueFamilyIndices.h"

bool QueueFamilyIndices::IsComplete() {
    return GraphicsFamily.has_value();
}
