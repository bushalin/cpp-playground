#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace thread_test {
class ThreadTest {
public:
  ThreadTest();
  ~ThreadTest();
  void Test1();
  void TestWithInt(int a);
  void TestWithString(const std::string &a);
};

} // namespace thread_test
