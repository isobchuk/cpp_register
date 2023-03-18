#pragma once

#include "register.hpp"

namespace stm32f407::gpio {

using namespace peripheral;

template <const RegisterAddress address> struct GPIO_T {
  static constexpr Register<address + 0x0, AccessMode::RW, uint32_t, struct MODER> MODER{};
  static constexpr Register<address + 0x4, AccessMode::RW, uint32_t, struct OTYPER> OTYPER{};
  static constexpr Register<address + 0x8, AccessMode::RW, uint32_t, struct OSPEEDR> OSPEEDR{};
  static constexpr Register<address + 0xC, AccessMode::RW, uint32_t, struct PUPDR> PUPDR{};
  static constexpr Register<address + 0x10, AccessMode::R, uint32_t, struct IDR> IDR{};
  static constexpr Register<address + 0x14, AccessMode::RW, uint32_t, struct ODR> ODR{};
  static constexpr Register<address + 0x18, AccessMode::W, uint32_t, struct BSRR> BSRR{};
  static constexpr Register<address + 0x1C, AccessMode::RW, uint32_t, struct LCKR> LCKR{};
  static constexpr Register<address + 0x20, AccessMode::RW, uint32_t, struct AFRL> AFRL{};
  static constexpr Register<address + 0x24, AccessMode::RW, uint32_t, struct AFRH> AFRH{};
};

inline constexpr GPIO_T<0x40022000> const *GPIOI{};
inline constexpr GPIO_T<0x40021C00> const *GPIOH{};
inline constexpr GPIO_T<0x40021800> const *GPIOG{};
inline constexpr GPIO_T<0x40021400> const *GPIOF{};
inline constexpr GPIO_T<0x40021000> const *GPIOE{};
inline constexpr GPIO_T<0X40020C00> const *GPIOD{};
inline constexpr GPIO_T<0x40020800> const *GPIOC{};
inline constexpr GPIO_T<0x40022400> const *GPIOJ{};
inline constexpr GPIO_T<0x40022800> const *GPIOK{};
inline constexpr GPIO_T<0x40020400> const *GPIOB{};
inline constexpr GPIO_T<0x40020000> const *GPIOA{};

struct GPIO_MODER {
  static constexpr Field<decltype(GPIOI->MODER), (1UL << 0), AccessMode::RW, 2, 16> MODER{};
};

struct GPIO_OTYPER {
  static constexpr Field<decltype(GPIOI->OTYPER), (1UL << 0), AccessMode::RW, 1, 16> OT{};
};

struct GPIO_OSPEEDR {
  static constexpr Field<decltype(GPIOI->OSPEEDR), (1UL << 0), AccessMode::RW, 2, 16> OSPEEDR{};
};

struct GPIO_PUPDR {
  static constexpr Field<decltype(GPIOI->PUPDR), (1UL << 0), AccessMode::RW, 2, 16> PUPDR{};
};

struct GPIO_IDR {
  static constexpr Field<decltype(GPIOI->IDR), (1UL << 0), AccessMode::R, 1, 16> IDR{};
};

struct GPIO_ODR {
  static constexpr Field<decltype(GPIOI->ODR), (1UL << 0), AccessMode::RW, 1, 16> ODR{};
};

struct GPIO_BSRR {
  static constexpr Field<decltype(GPIOI->BSRR), (1UL << 16), AccessMode::W, 1, 16> BR{};
  static constexpr Field<decltype(GPIOI->BSRR), (1UL << 0), AccessMode::W, 1, 16> BS{};
};

struct GPIO_LCKR {
  static constexpr Field<decltype(GPIOI->LCKR), (1UL << 16), AccessMode::RW, 1> LCKK{};
  static constexpr Field<decltype(GPIOI->LCKR), (1UL << 0), AccessMode::RW, 1, 16> LCK{};
};

struct GPIO_AFRL {
  static constexpr Field<decltype(GPIOI->AFRL), (1UL << 0), AccessMode::RW, 4, 8> AFRL{};
};

struct GPIO_AFRH {
  static constexpr Field<decltype(GPIOI->AFRH), (1UL << 0), AccessMode::RW, 4, 8> AFRH{};
};

} // namespace stm32f407::gpio
