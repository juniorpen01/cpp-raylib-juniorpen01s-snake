#include <ranges>

#include <doctest/doctest.h>

#include <snake.hpp>

TEST_CASE("Snake of initial position (18, 13), initial length 8, initial "
          "direction left has body (18, 13..=6)") {
  const Snake snake({18, 13}, 2, Dir::Left);
  for (const auto [i, segment] :
       std::views::zip(std::views::iota(0), snake.get_body())) {
    CHECK_EQ(segment, Vector2(18 + i, 13));
  }
}

TEST_CASE("Snake of initial position (7, 7), initial length 4, initial "
          "direction up upon move down will continue to move up and has body "
          "(7, 6..=10)") {
  Snake snake({7, 7}, 4, Dir::Up);
  snake.set_direction(Dir::Down);
  snake.move();
  for (const auto [i, segment] :
       std::views::zip(std::views::iota(0), snake.get_body())) {
    CHECK_EQ(segment, Vector2(7, 6 + i));
  }
}

TEST_CASE("Snake of initial position (9, 5), initial length 10, initial "
          "direction left upon move up has body [(9, 4), (9..=17, 5)]") {
  Snake snake({9, 5}, 10, Dir::Left);
  snake.set_direction(Dir::Up);
  snake.move();
  CHECK_EQ(snake.get_body().at(0), Vector2(9, 4));
  for (const auto [i, segment] : std::views::zip(
           std::views::iota(0), snake.get_body() | std::views::drop(1))) {
    CHECK_EQ(segment, Vector2(9 + i, 5));
  }
}

TEST_CASE(
    "Snake of initial position (6, 0), initial length 7, initial direction "
    "down upon move left and down has body [(5, 0), (5, 1), (6, 6..=0)]") {
  Snake snake({6, 0}, 7, Dir::Down);
  snake.set_direction(Dir::Left);
  snake.move();
  snake.set_direction(Dir::Down);
  snake.move();
  CHECK_EQ(snake.get_body().at(0), Vector2(5, 1));
  CHECK_EQ(snake.get_body().at(1), Vector2(5, 0));
  for (const auto [i, segment] : std::views::zip(
           std::views::iota(0), snake.get_body() | std::views::drop(2))) {
    CHECK_EQ(segment, Vector2(6, -i));
  }
}

// TODO: 3
TEST_CASE(
    "Snake of initial position (6, 0), initial length 5, initial direction "
    "down has grow position (6, -5) and upon move left has grow position (6, "
    "-4)") {
  Snake snake({6, 0}, 5, Dir::Down);
  CHECK_EQ(snake.get_position_grow(), Vector2(6, -5));
  snake.move();
  CHECK_EQ(snake.get_position_grow(), Vector2(6, -4));
}
