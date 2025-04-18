#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <optional>
#include <string_view>

#include <raylib.h>

#include <str.hpp>

enum struct Dir { Left, Down, Up, Right };

class Direction {
  const Dir value;

public:
  static constexpr std::optional<Direction> from_str(std::string_view str) {
    std::string str_upper = to_uppercase(str);
    if (str_upper == "LEFT") {
      return Dir::Left;
    } else if (str_upper == "DOWN") {
      return Dir::Down;
    } else if (str_upper == "UP") {
      return Dir::Up;
    } else if (str_upper == "RIGHT") {
      return Dir::Right;
    } else {
      return std::nullopt;
    }
  }
  constexpr Direction(Dir value) : value(value) {}
  constexpr Dir operator*() const;
  constexpr Direction operator-() const {
    switch (value) {
    case Dir::Left:
      return Dir::Right;
    case Dir::Down:
      return Dir::Up;
    case Dir::Up:
      return Dir::Down;
    case Dir::Right:
      return Dir::Left;
    }
  }
  constexpr std::string_view as_str() const;
  constexpr Vector2 into_vector2() const {
    switch (value) {
    case Dir::Left:
      return {-1, 0};
    case Dir::Down:
      return {0, 1};
    case Dir::Up:
      return {0, -1};
    case Dir::Right:
      return {1, 0};
    }
  }
};

#endif
