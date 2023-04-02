#pragma once

#include "register.hpp"

namespace stm32f407::stk {

template <const isob::peripheral::RegisterAddress address> struct STK_T {
  static constexpr isob::peripheral::Register<address + 0x0, isob::peripheral::AccessMode::RW, uint32_t, struct CTRL>
      CTRL{};
  static constexpr isob::peripheral::Register<address + 0x4, isob::peripheral::AccessMode::RW, uint32_t, struct LOAD>
      LOAD{};
  static constexpr isob::peripheral::Register<address + 0x8, isob::peripheral::AccessMode::RW, uint32_t, struct VAL>
      VAL{};
  static constexpr isob::peripheral::Register<address + 0xC, isob::peripheral::AccessMode::RW, uint32_t, struct CALIB>
      CALIB{};
};

inline constexpr STK_T<0xE000E010> const *STK{};

struct STK_CTRL {
  static constexpr isob::peripheral::Field<decltype(STK->CTRL), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      ENABLE{};
  static constexpr isob::peripheral::Field<decltype(STK->CTRL), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      TICKINT{};
  static constexpr isob::peripheral::Field<decltype(STK->CTRL), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      CLKSOURCE{};
  static constexpr isob::peripheral::Field<decltype(STK->CTRL), (1UL << 16), isob::peripheral::AccessMode::RW, 1>
      COUNTFLAG{};
};

struct STK_LOAD {
  static constexpr isob::peripheral::Field<decltype(STK->LOAD), (1UL << 0), isob::peripheral::AccessMode::RW, 24>
      RELOAD{};
};

struct STK_VAL {
  static constexpr isob::peripheral::Field<decltype(STK->VAL), (1UL << 0), isob::peripheral::AccessMode::RW, 24>
      CURRENT{};
};

struct STK_CALIB {
  static constexpr isob::peripheral::Field<decltype(STK->CALIB), (1UL << 0), isob::peripheral::AccessMode::RW, 24>
      TENMS{};
  static constexpr isob::peripheral::Field<decltype(STK->CALIB), (1UL << 30), isob::peripheral::AccessMode::RW, 1>
      SKEW{};
  static constexpr isob::peripheral::Field<decltype(STK->CALIB), (1UL << 31), isob::peripheral::AccessMode::RW, 1>
      NOREF{};
};

} // namespace stm32f407::stk
