#include "Utils/ImageManager.hpp"

#include <filesystem>

namespace ImageRain::ImageManager
{
    void ManageImagesPath()
    {
        std::string path = ModDir;
        if (!std::filesystem::exists(path)) 
        {
            std::filesystem::create_directories(path);
            return;
        }

        //for (auto file : std::filesystem::directory_iterator(path))
    }
}