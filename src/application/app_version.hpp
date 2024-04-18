#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace app_version {
class AppVersion {
public:
  AppVersion();
  ~AppVersion();
  void VerifyFilePath();
  void CreateVersionFile(const std::string& value);
  std::string GetVersion();

private:
  std::string version_file_;
  std::string asset_directory_;
  std::string app_version_;
};

} // namespace app_version
