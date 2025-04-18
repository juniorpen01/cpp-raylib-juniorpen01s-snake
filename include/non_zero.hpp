#ifndef NON_ZERO_HPP
#define NON_ZERO_HPP

#include <optional>

template <typename T> class NonZero {
  const T value;
  constexpr NonZero(T value) : value(value) {}

public:
  static constexpr std::optional<NonZero> init(T value) {
    if (value != 0)
      return NonZero(value);
    return std::nullopt;
  }
  constexpr T operator*() const { return value; }
};

#endif
