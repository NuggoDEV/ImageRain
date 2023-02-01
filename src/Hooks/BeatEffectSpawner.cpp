#include "main.hpp"
#include "modConfig.hpp"
#include "hooks.hpp"

#include "Utils/FileUtils.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;


float speed = 0.1f;
RectTransform rectTransform;

GameObject *leftImage;

MAKE_AUTO_HOOK_MATCH(BeatEffectSpawner_Start, &BeatEffectSpawner::Start, void, BeatEffectSpawner *self)
{
    BeatEffectSpawner_Start(self);

    const std::string path = ModDir;

    std::vector<std::string> images = FileUtils::getFiles(path);
    for (int i = 0; i < images.size(); i++)
    {
        auto image = images.at(i);
        std::string fileName = FileUtils::GetFileName(path, false);

        if (fileName == getModConfig().LeftSelected.GetValue())
        {
            auto screen = BeatSaberUI::CreateFloatingScreen({0.1, 0.1}, {-5.0, 15.0, -15.0}, )
            leftImage = BeatSaberUI::CreateImage(screen->get_transform(), image)
        }

    }
}

MAKE_AUTO_HOOK_MATCH(BeatEffectSpawner_Update, &BeatEffectSpawner::Update, void, BeatEffectSpawner *self)
{
    BeatEffectSpawner_Update(self);

    
}