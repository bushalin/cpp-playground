#include "app_version.hpp"
#include "image_module.hpp"
#include "thread_test.hpp"

#include <iostream>

void CheckArguments(int argc, char *argv[]) {
  int i = 0;
  while (i < argc) {
    if (!std::strcmp(argv[i], "--version")) {
      app_version::AppVersion av;
      std::string version_info = av.GetVersion();
      std::cout << version_info << std::endl;
    }
    if (!std::strcmp(argv[i], "--create-version")) {
      std::string new_version;
      int temp = i + 1;
      app_version::AppVersion av;
      av.CreateVersionFile(new_version);
      std::string latest;
      latest = av.GetVersion();
      std::cout << latest << std::endl;
    }
    i++;
  }
}

int main(int argc, char *argv[]) {
  CheckArguments(argc, argv);
  return 0;
}

/* std::string dirPath = "./assets/images"; */
/* image_module::ImageHandler *image_handler_; */

/* image_handler_ = image_module::ImageHandler::GetReference(); */
/* thread_test::ThreadTest th; */

/* auto start_time = std::chrono::high_resolution_clock::now(); */
/* std::thread t1(&image_module::ImageHandler::Convert2GrayScaleImage, */
/*                image_handler_, std::cref(dirPath)); */
/* std::thread t2(&thread_test::ThreadTest::TestWithString, &th, */
/*                std::ref(dirPath)); */
/* t1.join(); */
/* t2.join(); */
/* auto stop_time = std::chrono::high_resolution_clock::now(); */
/* auto duration = */
/*     std::chrono::duration_cast<std::chrono::seconds>(stop_time -
 * start_time); */
/* std::cout << "Time: " << duration.count() << std::endl; */
/* return 0; */
