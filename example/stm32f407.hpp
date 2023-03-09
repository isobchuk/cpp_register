#pragma once

#include "register.hpp"

static_assert((__cplusplus >= 201703L), "Supported only with C++17 and newer!");

namespace stm32f407::registers {

using namespace peripheral;

namespace rcc {

template <const RegisterAddress address> struct RCC_T {
  static constexpr Register<address + 0x30, AccessMode::RW, uint32_t> AHB1ENR{};
};

inline constexpr RCC_T<0x40023800UL> const *RCC{};

struct RCC_AHB1ENR {
  static constexpr Field<decltype(RCC->AHB1ENR), (1UL << 3), AccessMode::RW, 1> GPIODEN{};
};

} // namespace rcc

namespace system_tick {

template <const RegisterAddress address> struct SYST_T {
  static constexpr Register<address, AccessMode::RW, uint32_t> CSR{};
  static constexpr Register<address + 0x04, AccessMode::RW, uint32_t> RVR{};
  static constexpr Register<address + 0x08, AccessMode::RW, uint32_t> CVR{};
  static constexpr Register<address + 0x0C, AccessMode::RW, uint32_t> CALIB{};
};

inline constexpr SYST_T<0xE000E010UL> const *SYST{};

struct SYST_CSR {
  static constexpr Field<decltype(SYST->CSR), (1UL << 0), AccessMode::RW, 1> ENABLE{};
  static constexpr Field<decltype(SYST->CSR), (1UL << 1), AccessMode::RW, 1> TICKINT{};
  static constexpr Field<decltype(SYST->CSR), (1UL << 2), AccessMode::RW, 1> CLKSOURCE{};
  static constexpr Field<decltype(SYST->CSR), (1UL << 16), AccessMode::R, 1> COUNTFLAG{};
};

struct SYST_RVR {
  static constexpr Field<decltype(SYST->RVR), (1UL << 0), AccessMode::RW, 24> RELOAD{};
};

struct SYST_CVR {
  static constexpr Field<decltype(SYST->CVR), (1UL << 0), AccessMode::RW, 32> CURRENT{};
};

struct SYST_CALIB {
  static constexpr Field<decltype(SYST->CALIB), (1UL << 0), AccessMode::RW, 24> TENMS{};
  static constexpr Field<decltype(SYST->CALIB), (1UL << 30), AccessMode::RW, 1> SKEW{};
  static constexpr Field<decltype(SYST->CALIB), (1UL << 31), AccessMode::RW, 1> NOREF{};
};
} // namespace system_tick

namespace gpio {

template <const RegisterAddress address> struct GPIO_T {
  static constexpr Register<address, AccessMode::RW, uint32_t> MODER{};
  static constexpr Register<address + 0x14, AccessMode::W, uint32_t> ODR{};
  static constexpr Register<address + 0x18, AccessMode::W, uint32_t> BSRR{};
};

inline constexpr GPIO_T<0x40020C00UL> const *GPIOD{};

struct GPIO_MODER {
  static constexpr Field<decltype(GPIOD->MODER), (1UL << 0), AccessMode::RW, 2, 16> MODER{};
};

struct GPIO_BSRR {
  static constexpr Field<decltype(GPIOD->BSRR), (1UL << 0), AccessMode::RW, 1, 16> BS{};
  static constexpr Field<decltype(GPIOD->BSRR), (1UL << 16), AccessMode::RW, 1, 16> BR{};
};

struct GPIO_ODR {
  static constexpr Field<decltype(GPIOD->ODR), (1UL << 0), AccessMode::RW, 1, 16> ODR{};
};

} // namespace gpio
} // namespace stm32f407::registers
