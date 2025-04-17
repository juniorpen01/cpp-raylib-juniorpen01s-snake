#include <cstring>

#include <hello.hpp>

const char *hello_good() {
  const char *const hello = "Hello, World!";
  return hello;
}

char *hello_bad() {
  char *const hello = new char[14];
  strcpy(hello, "Hello, World!");
  return hello;
}
