#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

namespace fs = std::filesystem;

namespace image_module {

class ImageHandler {
public:
  ImageHandler();
  ~ImageHandler();
  static ImageHandler *GetReference();
  void Convert2GrayScaleImage(const std::string &dir);

private:
  static ImageHandler *instance_;
  cv::Mat image_;
  const std::string output_directory_path_ = "./output/";

  void ReplaceExtension(std::string &str, const std::string &oldStr = "png",
                        const std::string &newStr = "jpg");

  std::string CreateOutputFilename(const fs::path &filename);

  void VerifyOutputDirectory();
};

} // namespace image_module
