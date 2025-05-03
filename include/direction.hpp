#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <stdexcept>

#include <raylib.h>
#include <raymath.h>

enum class Dir { Left, Down, Up, Right };

class Direction {
  Dir value;

public:
  constexpr Direction(const Dir value) : value(value) {}

  constexpr const Vector2 into_vector2() const {
    switch (value) {
    case Dir::Left:
      return {-1, 0};
    case Dir::Down:
      return {0, 1};
    case Dir::Up:
      return {0, -1};
    case Dir::Right:
      return {1, 0};
    default:
      throw std::invalid_argument("Direction variant not found");
    }
  }

  constexpr const Direction operator-() const {
    switch (value) {
    case Dir::Left:
      return Dir::Right;
    case Dir::Down:
      return Dir::Up;
    case Dir::Up:
      return Dir::Down;
    case Dir::Right:
      return Dir::Left;
    default:
      throw std::invalid_argument("Direction variant not found");
    }
  }

  constexpr bool operator==(const Direction other) const {
    return this->value == other.value;
  }
};

#endif
