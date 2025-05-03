#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <functional>
#include <vector>

template <typename... Args> class Signal {
  using Slot = const std::function<void(const Args...)>;
  std::vector<Slot> listeners;

public:
  constexpr void connect(const Slot slot) {
    listeners.emplace_back(std::move(slot));
  }

  constexpr void emit(const Args... args) const {
    for (auto &listener : listeners) {
      listener(args...);
    }
  }
};

#endif
