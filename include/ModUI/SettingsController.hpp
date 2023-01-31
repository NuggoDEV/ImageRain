#pragma once

#include "main.hpp"

#include "HMUI/ViewController.hpp"
#include "custom-types/shared/macros.hpp"

#include "ModUI/ImageSelectController.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(ImageRain::UI, SettingsController, HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(ImageRain::UI::ImageSelectController*, imageSelectController);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&HMUI::ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)