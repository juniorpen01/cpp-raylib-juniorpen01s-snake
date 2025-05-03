#ifndef FOOD_HPP
#define FOOD_HPP

#include <raylib.h>

#include <signal.hpp>

class Food {
  Vector2 position;
  Signal<> signal;

public:
  Food(Vector2 position) : position(position) {}

  constexpr void set_position(Vector2 position) { this->position = position; }

  void connect(const std::function<void()> slot) { signal.connect(slot); }
};

#endif
