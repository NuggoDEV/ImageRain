#include "ModUI/ImageSelectController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(ImageRain::UI, ImageSelectController);

void ImageRain::UI::ImageSelectController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation) return;
}