#include "thread_test.hpp"

namespace thread_test {
ThreadTest::ThreadTest(){};
ThreadTest::~ThreadTest(){};
void ThreadTest::Test1() { std::cout << "print value of Test1()" << std::endl; }
void ThreadTest::TestWithInt(int a) {
  std::cout << "Printing value of a: " << a << std::endl;
}

void ThreadTest::TestWithString(const std::string &a) {
  for (int i = 0; i < 10; i++) {
    std::cout << "Printing string a: " << a << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
} // namespace thread_test
