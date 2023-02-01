#include "main.hpp"
#include "ModUI/RightImageSelectController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include <vector>
#include <filesystem>

DEFINE_TYPE(ImageRain::UI, RightImageSelectController);

void ImageRain::UI::RightImageSelectController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation) return;
    const std::string path = ModDir + "/Images";

    auto cont = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());

    auto text = BeatSaberUI::CreateText(cont->get_transform(), "Right Screen!");
        text->set_alignment(TMPro::TextAlignmentOptions::Center);

}