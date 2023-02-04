#include "main.hpp"
#include "modConfig.hpp"
#include "ModUI/SettingsController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(ImageRain::UI, SettingsController);

void ImageRain::UI::SettingsController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation) return;

    auto cont = BeatSaberUI::CreateScrollView(get_transform());

    BeatSaberUI::CreateToggle(cont->get_transform(), "Enable Mod", getModConfig().ModToggle.GetValue(), [](bool value)
    {
        getModConfig().ModToggle.SetValue(value);
    });

    BeatSaberUI::CreateToggle(cont->get_transform(), "Enable Left Side", getModConfig().LeftEnabled.GetValue(), [](bool value)
    {
        getModConfig().LeftEnabled.SetValue(value);
    });

    BeatSaberUI::CreateToggle(cont->get_transform(), "Enable Right Side", getModConfig().RightEnabled.GetValue(), [](bool value)
    {
        getModConfig().RightEnabled.SetValue(value);
    });
}