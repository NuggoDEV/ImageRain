#include "main.hpp"
#include "ModUI/LeftImageSelectController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include <vector>
#include <filesystem>

DEFINE_TYPE(ImageRain::UI, LeftImageSelectController);

void ImageRain::UI::LeftImageSelectController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation) return;
    const std::string path = ModDir + "/Images";

    auto cont = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());

    auto text = BeatSaberUI::CreateText(cont->get_transform(), "Left Screen!");
        text->set_alignment(TMPro::TextAlignmentOptions::Center);

}