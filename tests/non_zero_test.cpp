#include <doctest/doctest.h>

#include <non_zero.hpp>

TEST_CASE("Passing in non-zero to NonZero init constructor and calling the "
          "value method is perfectly fine") {
  CHECK_NOTHROW(NonZero<int>::init(4).value());
}

TEST_CASE("Passing in zero to NonZero init constructor and calling the value "
          "method panics") {
  CHECK_THROWS(NonZero<int>::init(0).value());
}
