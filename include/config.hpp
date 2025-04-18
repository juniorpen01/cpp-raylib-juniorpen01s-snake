#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <raylib.h>
#include <toml++/toml.hpp>

#include <direction.hpp>
#include <non_zero.hpp>

struct Config {
  const struct Snake {
    const Vector2 position_initial;
    const NonZero<unsigned int> length_initial;
    const Direction direction_initial;
  } snake;
  constexpr Config(const toml::table &tbl)
      : snake({tbl.at_path("snake.position_initial.x").value_or(15.f),
               tbl.at_path("snake.position_initial.y").value_or(15.f)},
              *NonZero<unsigned int>::init(
                  tbl.at_path("snake.length_initial").value_or(3)),
              *Direction::from_str(
                  tbl.at_path("snake.direction_initial").value_or("Up"))) {}
};

#endif
