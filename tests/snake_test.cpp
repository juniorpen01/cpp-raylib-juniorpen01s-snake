#include <doctest/doctest.h>

#include <ranges>

#include <snake.hpp>

TEST_CASE("Snake instance with initial position (10, 10), initial length 5, "
          "and initial direction up has the body (10, 10-14)") {
  Snake snake({10, 10}, *NonZero<unsigned int>::init(5), Dir::Up);

  for (auto [index, segment] :
       std::views::zip(std::views::iota(0), snake.get_body())) {
    CHECK_EQ(segment, Vector2(10, 10 + index));
  }
}
