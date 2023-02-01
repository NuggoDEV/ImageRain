#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ModToggle, bool, "ModToggle", false);
    CONFIG_VALUE(LeftEnabled, bool, "LeftEnabled", false);
    CONFIG_VALUE(RightEnabled, bool, "RightEnabled", false);

    CONFIG_VALUE(LeftSelected, std::string, "LeftSelected", "None");
    CONFIG_VALUE(RightSelected, std::string, "RightSelected", "None");
)