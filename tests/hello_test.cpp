#include <doctest/doctest.h>

#include <hello.hpp>

TEST_CASE("hello_good uses char pointer and returns a static string") {
  const char *const hello = hello_good();
  CHECK_EQ(hello, "Hello, World!");
}

TEST_CASE("hello_bad uses heap allocation with raw pointers") {
  char *hello = hello_bad();
  hello = nullptr;
  hello[6] = 'd';
}
