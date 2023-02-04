#include "main.hpp"
#include "modConfig.hpp"
#include "hooks.hpp"

#include "Utils/FileUtils.hpp"

#include "HMUI/ImageView.hpp"
using namespace HMUI;


#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"
#include "GlobalNamespace/BeatEffectSpawner.hpp"
using namespace GlobalNamespace;

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"


#include "UnityEngine/ParticleSystem.hpp"
#include "UnityEngine/ParticleSystem_MainModule.hpp"
#include "UnityEngine/ParticleSystem_SubEmittersModule.hpp"

#include "UnityEngine/Transform.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/Vector2.hpp"
using namespace UnityEngine;
using namespace UnityEngine::UI;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#define SetPreferredSize(identifier, width, height)                                         \
    auto layout##identifier = identifier->get_gameObject()->GetComponent<LayoutElement*>(); \
    if (!layout##identifier)                                                                \
        layout##identifier = identifier->get_gameObject()->AddComponent<LayoutElement*>();  \
    layout##identifier->set_preferredWidth(width);                                          \
    layout##identifier->set_preferredHeight(height)

Transform *leftGO1;
Transform *leftGO2;

Transform *rightGO1;



//ParticleSystem *test;//ParticleSystem::New_ctor<il2cpp_utils::CreationType::Manual>();
ParticleSystem *m_System;
ParticleSystem::Particle *m_Particles;
float m_Drift = 0.01f;

MAKE_AUTO_HOOK_MATCH(a, &BeatEffectSpawner::Start, void, BeatEffectSpawner *self)
{
    a(self);

    if (!getModConfig().ModToggle.GetValue()) return;

    
    

    std::vector<std::string> images = FileUtils::getFiles(ModDir);

    for (int i = 0; i < images.size(); i++)
    {
        auto image = images.at(i);

        if (FileUtils::GetFileName(image, false) == getModConfig().LeftSelected.GetValue() && getModConfig().LeftEnabled.GetValue())
        {

            int numParticlesAlive = m_System->GetParticles(m_Particles, 50);
            for (int i = 0; i < numParticlesAlive; i++) 
            {
                m_Particles[i].set_velocity(Vector3(0, 1, 0) * m_Drift);
            }

            m_System->SetParticles(m_Particles, numParticlesAlive);
            

            /*test->SetParticles(sprite, 50);
            test->get_transform()->set_localScale({5, 1, 1});
            test->get_transform()->set_position({-7, 10, 18});*/

            /*leftGO1 = GameObject::New_ctor("LeftGameObject1")->get_transform();
                leftGO1->set_position({-7, 8, 18});
                leftGO1->set_rotation({0, -25, 0});
            
            auto leftImg1 = BeatSaberUI::CreateImage(leftGO1->get_transform(), sprite, {0, 0}, {30, 30});
                SetPreferredSize(leftImg1, 10.0f, 2.0f);


            leftGO2 = GameObject::New_ctor("LeftGameObject2")->get_transform();
                leftGO2->set_position({-7, 8, 18});
                leftGO2->set_rotation({0, -25, 0});
            
            auto leftImg2 = BeatSaberUI::CreateImage(leftGO2->get_transform(), sprite, {0, 0}, {30, 30});
                SetPreferredSize(leftImg2, 10.0f, 2.0f);*/

        }

        /*if (FileUtils::GetFileName(image, false) == getModConfig().RightSelected.GetValue() && getModConfig().RightEnabled.GetValue())
        {
            auto sprite = BeatSaberUI::FileToSprite(image);
            Object::DontDestroyOnLoad(sprite);

            rightGO1 = GameObject::New_ctor("RightGameObject1")->get_transform();
                rightGO1->set_position({7, 8, 18});
                rightGO1->set_rotation({0, 25, 0});
            
            auto rightImg1 = BeatSaberUI::CreateImage(rightGO1->get_transform(), sprite, {0, 0}, {30, 30});
                SetPreferredSize(rightImg1, 10.0f, 2.0f);
        }*/
    }
}

MAKE_AUTO_HOOK_MATCH(b, &BeatEffectSpawner::Update, void, BeatEffectSpawner *self)
{
    b(self);
    /*auto leftPos1 = leftGO1->get_position();
    auto leftPos2 = leftGO2->get_position();

    auto rightPos1 = rightGO1->get_position();

    leftGO1->set_position({leftPos1.x, leftPos1.y - 0.01f, leftPos1.z});
    leftGO2->set_position({leftPos2.x, leftPos2.y - 0.01f});

    rightGO1->set_position({rightPos1.x, rightPos1.y - 0.01f, rightPos1.z});

    if (leftPos1.y < -0.5f)
    {
        leftGO1->set_position({leftPos1.x, 8, leftPos1.z});
    }

    if ()



    if (rightPos1.y < -0.5f)
    {
        rightGO1->set_position({rightPos1.x, 8, rightPos1.z});
    }*/
}

MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ShowMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
{
    PauseMenuManager_ShowMenu(self);

    //test->Pause(false);
}

MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ContinueButtonPressed,  &PauseMenuManager::ContinueButtonPressed, void, PauseMenuManager *self)
{
    PauseMenuManager_ContinueButtonPressed(self);

    //test->Play(true);
}