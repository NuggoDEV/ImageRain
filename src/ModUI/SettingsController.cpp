#include "ModUI/SettingsController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(ImageRain::UI, SettingsController);

void ImageRain::UI::SettingsController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation) return;
}