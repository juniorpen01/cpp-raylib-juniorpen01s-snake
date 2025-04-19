#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <format>

#include <raylib.h>

// INFO: Overload of the << operator is required to support output streaming in
// doctest
constexpr const std::ostream &operator<<(std::ostream &os,
                                         const Vector2 vector2) {
  os << std::format("({}, {})", vector2.x, vector2.y);
  return os;
}

template <> struct std::formatter<Vector2> : std::formatter<std::string> {
  constexpr auto format(const Vector2 vector2, std::format_context &ctx) const {
    return std::formatter<std::string>::format(
        std::format("{}: ({}, {})", sizeof(std::format_context), vector2.x,
                    vector2.y),
        ctx);
  }
};

#endif
