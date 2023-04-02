#pragma once

#include "register.hpp"

namespace stm32f407::gpio {

template <const isob::peripheral::RegisterAddress address> struct GPIO_T {
  static constexpr isob::peripheral::Register<address + 0x0, isob::peripheral::AccessMode::RW, uint32_t, struct MODER>
      MODER{};
  static constexpr isob::peripheral::Register<address + 0x4, isob::peripheral::AccessMode::RW, uint32_t, struct OTYPER>
      OTYPER{};
  static constexpr isob::peripheral::Register<address + 0x8, isob::peripheral::AccessMode::RW, uint32_t, struct OSPEEDR>
      OSPEEDR{};
  static constexpr isob::peripheral::Register<address + 0xC, isob::peripheral::AccessMode::RW, uint32_t, struct PUPDR>
      PUPDR{};
  static constexpr isob::peripheral::Register<address + 0x10, isob::peripheral::AccessMode::R, uint32_t, struct IDR>
      IDR{};
  static constexpr isob::peripheral::Register<address + 0x14, isob::peripheral::AccessMode::RW, uint32_t, struct ODR>
      ODR{};
  static constexpr isob::peripheral::Register<address + 0x18, isob::peripheral::AccessMode::W, uint32_t, struct BSRR>
      BSRR{};
  static constexpr isob::peripheral::Register<address + 0x1C, isob::peripheral::AccessMode::RW, uint32_t, struct LCKR>
      LCKR{};
  static constexpr isob::peripheral::Register<address + 0x24, isob::peripheral::AccessMode::RW, uint32_t, struct AFR, 2>
      AFR{};
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
  static constexpr isob::peripheral::Field<decltype(GPIOI->MODER), (1UL << 0), isob::peripheral::AccessMode::RW, 2, 16>
      MODER{};
};

struct GPIO_OTYPER {
  static constexpr isob::peripheral::Field<decltype(GPIOI->OTYPER), (1UL << 0), isob::peripheral::AccessMode::RW, 1, 16>
      OT{};
};

struct GPIO_OSPEEDR {
  static constexpr isob::peripheral::Field<decltype(GPIOI->OSPEEDR), (1UL << 0), isob::peripheral::AccessMode::RW, 2,
                                           16>
      OSPEEDR{};
};

struct GPIO_PUPDR {
  static constexpr isob::peripheral::Field<decltype(GPIOI->PUPDR), (1UL << 0), isob::peripheral::AccessMode::RW, 2, 16>
      PUPDR{};
};

struct GPIO_IDR {
  static constexpr isob::peripheral::Field<decltype(GPIOI->IDR), (1UL << 0), isob::peripheral::AccessMode::R, 1, 16>
      IDR{};
};

struct GPIO_ODR {
  static constexpr isob::peripheral::Field<decltype(GPIOI->ODR), (1UL << 0), isob::peripheral::AccessMode::RW, 1, 16>
      ODR{};
};

struct GPIO_BSRR {
  static constexpr isob::peripheral::Field<decltype(GPIOI->BSRR), (1UL << 16), isob::peripheral::AccessMode::W, 1, 16>
      BR{};
  static constexpr isob::peripheral::Field<decltype(GPIOI->BSRR), (1UL << 0), isob::peripheral::AccessMode::W, 1, 16>
      BS{};
};

struct GPIO_LCKR {
  static constexpr isob::peripheral::Field<decltype(GPIOI->LCKR), (1UL << 16), isob::peripheral::AccessMode::RW, 1>
      LCKK{};
  static constexpr isob::peripheral::Field<decltype(GPIOI->LCKR), (1UL << 0), isob::peripheral::AccessMode::RW, 1, 16>
      LCK{};
};

struct GPIO_AFR {
  static constexpr isob::peripheral::Field<decltype(GPIOI->AFR), (1UL << 0), isob::peripheral::AccessMode::RW, 4, 8>
      AFR{};
};
} // namespace stm32f407::gpio
