#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <deque>
#include <optional>

#include <raylib.h>
#include <raymath.h>

#include <direction.hpp>

class Snake {
  std::deque<Vector2> body;
  std::optional<Direction> direction;
  Vector2 position_grow;

public:
  constexpr Snake(const Vector2 position_initial, const int length_initial,
                  const Direction direction_initial)
      : direction(direction_initial) {
    for (int i = 0; i < length_initial; ++i) {
      body.push_back(position_initial -
                     Vector2Scale(direction_initial.into_vector2(), i));
    }
    position_grow = body.back() - direction_initial.into_vector2();
  }

  constexpr const std::deque<Vector2> &get_body() const { return body; }

  constexpr const std::optional<Direction> get_direction() const {
    return direction;
  }

  constexpr const Vector2 get_position() const { return body.front(); }

  constexpr const Vector2 get_position_grow() const { return position_grow; }

  constexpr void set_direction(std::optional<Direction> direction) {
    if (direction) {
      if (this->direction != -direction.value())
        this->direction = direction;
    } else {
      this->direction = direction;
    }
  }

  constexpr void move() {
    if (direction) {
      position_grow = body.back();
      body.pop_back();
      body.push_front(body.front() + direction->into_vector2());
    }
  }

  constexpr void grow() {
    Vector2 foo = position_grow - body.back();
    body.push_back(position_grow);
    position_grow += foo;
  }

  constexpr void on_food_eaten() { grow(); }
};

#endif
