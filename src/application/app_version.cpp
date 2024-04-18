#include "app_version.hpp"
#include <iostream>

namespace app_version {

AppVersion::AppVersion() {
  asset_directory_ = "./assets";
  version_file_ = asset_directory_ + "/app.version";
  app_version_ = "v1.0.0rc-5";
  AppVersion::VerifyFilePath();
};
AppVersion::~AppVersion(){};

void AppVersion::VerifyFilePath() {
  if (!fs::exists(asset_directory_)) {
    fs::create_directory(asset_directory_);
  }
  CreateVersionFile(app_version_);
}

void AppVersion::CreateVersionFile(const std::string &value) {
  std::ofstream file(version_file_);
  file << value;
  file.close();
}

std::string AppVersion::GetVersion() {
  std::ifstream file(version_file_);
  std::string version;
  while (std::getline(file, version)) {
    std::cout << version << std::endl;
  }
  file.close();
  return version;
}

} // namespace app_version
