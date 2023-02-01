#include "main.hpp"
#include "modConfig.hpp"
#include "ModUI/RightImageSelectController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "Utils/FileUtils.hpp"

#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/Vector2.hpp"
using namespace UnityEngine;
using namespace UnityEngine::UI;

#include <vector>
#include <filesystem>

DEFINE_TYPE(ImageRain::UI, RightImageSelectController);


// TAKEN FROM OPTIMUS' MOD, IMAGE FACTORY!
#define SetPreferredSize(identifier, width, height)                                         \
    auto layout##identifier = identifier->get_gameObject()->GetComponent<LayoutElement*>(); \
    if (!layout##identifier)                                                                \
        layout##identifier = identifier->get_gameObject()->AddComponent<LayoutElement*>();  \
    layout##identifier->set_preferredWidth(width);                                          \
    layout##identifier->set_preferredHeight(height)


TMPro::TextMeshProUGUI *rightText;

void ImageRain::UI::RightImageSelectController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    SetName(this, "Right Side Images");


    if (!firstActivation) return;
    const std::string path = ModDir;

    auto cont = BeatSaberUI::CreateScrollView(get_transform());
    
    std::vector<std::string> images = FileUtils::getFiles(path);


    if (images.size() == 0) 
    {
        auto text = BeatSaberUI::CreateText(cont->get_transform(), "\n\nNo images found!\nMake sure to add images to the path below:\n'sdcard/ModData/com.beatgames.beatsaber/Mods/ImageRain/Images'");
            text->set_alignment(TMPro::TextAlignmentOptions::Center);
            text->set_fontSize(3.5f);
    }
    else
    {
        rightText = BeatSaberUI::CreateText(cont->get_transform(), "");

        for (int i = 0; i < images.size(); i++) 
        {
            auto image = images.at(i);

            auto levelBarLayout = BeatSaberUI::CreateHorizontalLayoutGroup(cont->get_transform());
                levelBarLayout->set_childControlWidth(false);
            
            auto levelBarElement = levelBarLayout->GetComponent<LayoutElement *>();
                levelBarElement->set_minHeight(10.0f);
                levelBarElement->set_minWidth(20.0f);

            auto sprite = BeatSaberUI::FileToSprite(image);
            Object::DontDestroyOnLoad(sprite);

            auto img = BeatSaberUI::CreateImage(levelBarElement->get_transform(), sprite, Vector2(0.0f, 0.0f), Vector2(10.0f, 2.0f));
            SetPreferredSize(img, 10.0f, 2.0f);

            BeatSaberUI::CreateClickableText(levelBarElement->get_transform(), FileUtils::GetFileName(image, true), true, [image]()
            {
                std::string imgPath = FileUtils::GetFileName(image, false);
                getModConfig().RightSelected.SetValue(imgPath.c_str());
            });
            levelBarElement->set_minWidth(1.0f);
        }
    }

}


void ImageRain::UI::RightImageSelectController::Update()
{
    rightText->SetText("Currently Selected: " + getModConfig().RightSelected.GetValue());
    rightText->set_alignment(TMPro::TextAlignmentOptions::Center);
    rightText->set_fontSize(3.5f);
}   