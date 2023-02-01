// TAKEN FROM OPTIMUS' MOD, IMAGE FACTORY. FILE LINKED BELOW!
// https://github.com/OptimusChen/ImageFactory-Quest/blob/master/include/Utils/FileUtils.hpp

#pragma once

#include <string>

#include "custom-types/shared/macros.hpp"
#include "custom-types/shared/types.hpp"
#include "System/IO/FileStream.hpp"

namespace FileUtils {
    bool isImageFile(std::string_view path);
    std::string RemoveExtension(std::string path);
    std::string GetFileName(std::string path, bool removeExtension);
    std::vector<std::string> getFiles(std::string_view path);
    bool isGifFile(std::string_view path);
    bool isJsonFile(std::string_view path);
    long GetFileSize(std::string_view filename, System::IO::FileStream* stream);
    int FileSizeDivisor(long size);
    std::string FileSizeExtension(long size);
}  