#ifndef STR_HPP
#define STR_HPP

#include <cctype>
#include <ranges>
#include <string>

constexpr std::string to_uppercase(std::string_view str) {
  auto str_upper =
      str | std::views::transform([](char c) { return std::toupper(c); });
  return std::string(str_upper.begin(), str_upper.end());
}

#endif
