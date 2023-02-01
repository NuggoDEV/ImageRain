// TAKEN FROM OPTIMUS' MOD, IMAGE FACTORY. FILE LINKED BELOW!
// https://github.com/OptimusChen/ImageFactory-Quest/blob/master/src/Utils/FileUtils.cpp

#include "Utils/FileUtils.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace FileUtils {

  std::vector<std::string> getFiles(std::string_view path) {
    std::vector<std::string> directories;
    if (!std::filesystem::is_directory(path)) return directories;
    std::error_code ec;
    auto directory_iterator = std::filesystem::directory_iterator(path, std::filesystem::directory_options::none, ec);
    if (ec) {
    }
    for (const auto& entry : directory_iterator) {
      if (entry.is_regular_file()) directories.push_back(entry.path().string());
    }
    return directories;
  }

  std::string RemoveExtension(std::string path) {
    if (path.find_last_of(".") != std::string::npos)
      return path.substr(0, path.find_last_of("."));
    return path;
  }

  std::string GetFileName(std::string path, bool removeExtension) {
    std::string result = "";
    if (path.find_last_of("/") != std::string::npos)
      result = path.substr(path.find_last_of("/") + 1);
    else
      result = path;
    if (removeExtension) result = RemoveExtension(result);
    return result;
    ;
  }

  bool isImageFile(std::string_view path) {
    if (path.ends_with(".png") || path.ends_with(".jpg")) {
      return true;
    }
    return false;
  }

  bool isGifFile(std::string_view path) {
    if (path.ends_with(".gif")) {
      return true;
    }
    return false;
  }

  bool isJsonFile(std::string_view path) {
    if (path.ends_with(".json")) {
      return true;
    }
    return false;
  }

  std::string FileSizeExtension(long size) {
    if (size > 1000000) return "MB";
    if (size > 1000)
      return "KB";
    else
      return "bytes";
  }

  int FileSizeDivisor(long size) {
    if (size > 1000000) return 1000000;
    if (size > 1000)
      return 1000;
    else
      return 1;
  }

  long GetFileSize(std::string_view filename, System::IO::FileStream* stream) {
    return stream->get_Length();
  }
}