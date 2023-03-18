#pragma once

#include "register.hpp"

namespace stm32f407::stk {

using namespace peripheral;

template <const RegisterAddress address> struct STK_T {
  static constexpr Register<address + 0x0, AccessMode::RW, uint32_t, struct CTRL> CTRL{};
  static constexpr Register<address + 0x4, AccessMode::RW, uint32_t, struct LOAD> LOAD{};
  static constexpr Register<address + 0x8, AccessMode::RW, uint32_t, struct VAL> VAL{};
  static constexpr Register<address + 0xC, AccessMode::RW, uint32_t, struct CALIB> CALIB{};
};

inline constexpr STK_T<0xE000E010> const *STK{};

struct STK_CTRL {
  static constexpr Field<decltype(STK->CTRL), (1UL << 0), AccessMode::RW, 1> ENABLE{};
  static constexpr Field<decltype(STK->CTRL), (1UL << 1), AccessMode::RW, 1> TICKINT{};
  static constexpr Field<decltype(STK->CTRL), (1UL << 2), AccessMode::RW, 1> CLKSOURCE{};
  static constexpr Field<decltype(STK->CTRL), (1UL << 16), AccessMode::RW, 1> COUNTFLAG{};
};

struct STK_LOAD {
  static constexpr Field<decltype(STK->LOAD), (1UL << 0), AccessMode::RW, 24> RELOAD{};
};

struct STK_VAL {
  static constexpr Field<decltype(STK->VAL), (1UL << 0), AccessMode::RW, 24> CURRENT{};
};

struct STK_CALIB {
  static constexpr Field<decltype(STK->CALIB), (1UL << 0), AccessMode::RW, 24> TENMS{};
  static constexpr Field<decltype(STK->CALIB), (1UL << 30), AccessMode::RW, 1> SKEW{};
  static constexpr Field<decltype(STK->CALIB), (1UL << 31), AccessMode::RW, 1> NOREF{};
};

} // namespace stm32f407::stk
