#include "image_module.hpp"

namespace image_module {

ImageHandler::ImageHandler() {}
ImageHandler::~ImageHandler() {}

ImageHandler *ImageHandler::instance_ = NULL;

ImageHandler *ImageHandler::GetReference() {
  if (NULL == instance_) {
    instance_ = new ImageHandler();
  }
  return instance_;
}

void ImageHandler::Convert2GrayScaleImage(const std::string &dir) {
  VerifyOutputDirectory();
  for (const auto &entry : fs::directory_iterator(dir)) {
    std::string output_file_name = CreateOutputFilename(entry.path().string());
    auto image = cv::imread(entry.path(), cv::IMREAD_COLOR);
    cv::cvtColor(image, image_, cv::COLOR_RGB2GRAY);
    cv::imwrite(output_file_name, image_);
    cv::waitKey(200);
  }
}

void ImageHandler::ReplaceExtension(std::string &str, const std::string &oldStr,
                                    const std::string &newStr) {
  std::string::size_type pos = 0u;
  while ((pos = str.find(oldStr, pos)) != std::string::npos) {
    str.replace(pos, oldStr.length(), newStr);
    pos += newStr.length();
  }
}

std::string ImageHandler::CreateOutputFilename(const fs::path &filename) {
  return output_directory_path_ + filename.stem().string() + ".jpg";
}

void ImageHandler::VerifyOutputDirectory() {
  fs::path output_directory(output_directory_path_);

  if (!fs::exists(output_directory)) {
    fs::create_directory(output_directory_path_);
  }
}

} // namespace image_module
