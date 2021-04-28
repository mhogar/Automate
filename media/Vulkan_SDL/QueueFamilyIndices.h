#pragma once

#include <optional>

struct QueueFamilyIndices {
    std::optional<uint32_t> GraphicsFamily;

    bool IsComplete();
};
