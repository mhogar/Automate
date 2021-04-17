#pragma once

#include <string>

struct Version {
    std::string CodeVersion;
    std::string APIVersion;

    static Version Core();
    static Version Interface();
};
