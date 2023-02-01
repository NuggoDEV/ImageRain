#include "ModUI/ImageRainFlowCoordinator.hpp"
#include "ModUI/SettingsController.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(ImageRain::UI, ImageRainFlow);

void ImageRain::UI::ImageRainFlow::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation) return;

    settingsController = BeatSaberUI::CreateViewController<ImageRain::UI::SettingsController *>();
    leftImageSelectController = BeatSaberUI::CreateViewController<ImageRain::UI::LeftImageSelectController *>();
    rightImageSelectController = BeatSaberUI::CreateViewController<ImageRain::UI::RightImageSelectController *>();

    showBackButton = true;

    ProvideInitialViewControllers(settingsController, leftImageSelectController, rightImageSelectController, nullptr, nullptr);
    SetTitle("Image Rain Settings!", HMUI::ViewController::AnimationType::In);
}

void ImageRain::UI::ImageRainFlow::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}