#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list>

#include <raylib.h>
#include <raymath.h>

#include <direction.hpp>
#include <non_zero.hpp>

class Snake {
  std::list<Vector2> body;

public:
  constexpr Snake(Vector2 position_initial,
                  NonZero<unsigned int> length_initial,
                  Direction direction_initial) {
    for (unsigned int i = 0; i < *length_initial; ++i) {
      body.push_back(position_initial +
                     Vector2Scale((-direction_initial).into_vector2(), i));
    }
  }
  const constexpr std::list<Vector2> &get_body() const { return body; }
};

#endif
