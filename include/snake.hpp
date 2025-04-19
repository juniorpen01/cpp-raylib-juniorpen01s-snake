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
  std::optional<Vector2> last_previous;

public:
  constexpr Snake(const Vector2 position_initial, const int length_initial,
                  const Direction direction_initial)
      : direction(direction_initial), last_previous(std::nullopt) {
    for (int i = 0; i < length_initial; ++i) {
      body.push_back(position_initial -
                     Vector2Scale(direction_initial.into_vector2(), i));
    }
  }

  constexpr const std::deque<Vector2> &get_body() const { return body; }

  constexpr const std::optional<Direction> get_direction() const {
    return direction;
  }

  constexpr const std::optional<Vector2> get_last_previous() const {
    return last_previous;
  }

  constexpr void set_direction(std::optional<Direction> direction) {
    if (direction) {
      if (this->direction != -(*direction))
        this->direction = direction;
    } else {
      this->direction = direction;
    }
  }

  constexpr void move() {
    last_previous = body.back();
    if (direction) {
      body.pop_back();
      body.push_front(body.front() + direction->into_vector2());
    }
  }
};

#endif
