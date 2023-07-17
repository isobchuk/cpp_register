#pragma once

#include "register.hpp"

namespace stm32f407::stk {

template <const cpp_register::RegisterAddress address> struct STK_T {
  static constexpr cpp_register::Register<address + 0x0, cpp_register::AccessMode::RW, uint32_t, struct CTRL> CTRL{};
  static constexpr cpp_register::Register<address + 0x4, cpp_register::AccessMode::RW, uint32_t, struct LOAD> LOAD{};
  static constexpr cpp_register::Register<address + 0x8, cpp_register::AccessMode::RW, uint32_t, struct VAL> VAL{};
  static constexpr cpp_register::Register<address + 0xC, cpp_register::AccessMode::RW, uint32_t, struct CALIB> CALIB{};
};

inline constexpr STK_T<0xE000E010> const *STK{};

struct STK_CTRL {
  static constexpr cpp_register::Field<decltype(STK->CTRL), (1UL << 0), cpp_register::AccessMode::RW, 1> ENABLE{};
  static constexpr cpp_register::Field<decltype(STK->CTRL), (1UL << 1), cpp_register::AccessMode::RW, 1> TICKINT{};
  static constexpr cpp_register::Field<decltype(STK->CTRL), (1UL << 2), cpp_register::AccessMode::RW, 1> CLKSOURCE{};
  static constexpr cpp_register::Field<decltype(STK->CTRL), (1UL << 16), cpp_register::AccessMode::RW, 1> COUNTFLAG{};
};

struct STK_LOAD {
  static constexpr cpp_register::Field<decltype(STK->LOAD), (1UL << 0), cpp_register::AccessMode::RW, 24> RELOAD{};
};

struct STK_VAL {
  static constexpr cpp_register::Field<decltype(STK->VAL), (1UL << 0), cpp_register::AccessMode::RW, 24> CURRENT{};
};

struct STK_CALIB {
  static constexpr cpp_register::Field<decltype(STK->CALIB), (1UL << 0), cpp_register::AccessMode::RW, 24> TENMS{};
  static constexpr cpp_register::Field<decltype(STK->CALIB), (1UL << 30), cpp_register::AccessMode::RW, 1> SKEW{};
  static constexpr cpp_register::Field<decltype(STK->CALIB), (1UL << 31), cpp_register::AccessMode::RW, 1> NOREF{};
};

} // namespace stm32f407::stk
