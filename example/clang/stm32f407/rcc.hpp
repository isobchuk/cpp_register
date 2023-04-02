#pragma once

#include "register.hpp"

namespace stm32f407::rcc {

template <const isob::peripheral::RegisterAddress address> struct RCC_T {
  static constexpr isob::peripheral::Register<address + 0x0, isob::peripheral::AccessMode::R, uint32_t, struct CR> CR{};
  static constexpr isob::peripheral::Register<address + 0x4, isob::peripheral::AccessMode::RW, uint32_t, struct PLLCFGR>
      PLLCFGR{};
  static constexpr isob::peripheral::Register<address + 0x8, isob::peripheral::AccessMode::RW, uint32_t, struct CFGR>
      CFGR{};
  static constexpr isob::peripheral::Register<address + 0xC, isob::peripheral::AccessMode::W, uint32_t, struct CIR>
      CIR{};
  static constexpr isob::peripheral::Register<address + 0x10, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB1RSTR>
      AHB1RSTR{};
  static constexpr isob::peripheral::Register<address + 0x14, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB2RSTR>
      AHB2RSTR{};
  static constexpr isob::peripheral::Register<address + 0x18, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB3RSTR>
      AHB3RSTR{};
  static constexpr isob::peripheral::Register<address + 0x20, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct APB1RSTR>
      APB1RSTR{};
  static constexpr isob::peripheral::Register<address + 0x24, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct APB2RSTR>
      APB2RSTR{};
  static constexpr isob::peripheral::Register<address + 0x30, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB1ENR>
      AHB1ENR{};
  static constexpr isob::peripheral::Register<address + 0x34, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB2ENR>
      AHB2ENR{};
  static constexpr isob::peripheral::Register<address + 0x38, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB3ENR>
      AHB3ENR{};
  static constexpr isob::peripheral::Register<address + 0x40, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct APB1ENR>
      APB1ENR{};
  static constexpr isob::peripheral::Register<address + 0x44, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct APB2ENR>
      APB2ENR{};
  static constexpr isob::peripheral::Register<address + 0x50, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB1LPENR>
      AHB1LPENR{};
  static constexpr isob::peripheral::Register<address + 0x54, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB2LPENR>
      AHB2LPENR{};
  static constexpr isob::peripheral::Register<address + 0x58, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct AHB3LPENR>
      AHB3LPENR{};
  static constexpr isob::peripheral::Register<address + 0x60, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct APB1LPENR>
      APB1LPENR{};
  static constexpr isob::peripheral::Register<address + 0x64, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct APB2LPENR>
      APB2LPENR{};
  static constexpr isob::peripheral::Register<address + 0x70, isob::peripheral::AccessMode::RW, uint32_t, struct BDCR>
      BDCR{};
  static constexpr isob::peripheral::Register<address + 0x74, isob::peripheral::AccessMode::RW, uint32_t, struct CSR>
      CSR{};
  static constexpr isob::peripheral::Register<address + 0x80, isob::peripheral::AccessMode::RW, uint32_t, struct SSCGR>
      SSCGR{};
  static constexpr isob::peripheral::Register<address + 0x84, isob::peripheral::AccessMode::RW, uint32_t,
                                              struct PLLI2SCFGR>
      PLLI2SCFGR{};
};

inline constexpr RCC_T<0x40023800> const *RCC{};

struct RCC_CR {
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 27), isob::peripheral::AccessMode::R, 1>
      PLLI2SRDY{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 26), isob::peripheral::AccessMode::R, 1>
      PLLI2SON{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 25), isob::peripheral::AccessMode::R, 1> PLLRDY{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 24), isob::peripheral::AccessMode::R, 1> PLLON{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 19), isob::peripheral::AccessMode::R, 1> CSSON{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 18), isob::peripheral::AccessMode::R, 1> HSEBYP{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 17), isob::peripheral::AccessMode::R, 1> HSERDY{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 16), isob::peripheral::AccessMode::R, 1> HSEON{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 8), isob::peripheral::AccessMode::R, 8> HSICAL{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 3), isob::peripheral::AccessMode::R, 5> HSITRIM{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 1), isob::peripheral::AccessMode::R, 1> HSIRDY{};
  static constexpr isob::peripheral::Field<decltype(RCC->CR), (1UL << 0), isob::peripheral::AccessMode::R, 1> HSION{};
};

struct RCC_PLLCFGR {
  static constexpr isob::peripheral::Field<decltype(RCC->PLLCFGR), (1UL << 24), isob::peripheral::AccessMode::RW, 1, 4>
      PLLQ{};
  static constexpr isob::peripheral::Field<decltype(RCC->PLLCFGR), (1UL << 22), isob::peripheral::AccessMode::RW, 1>
      PLLSRC{};
  static constexpr isob::peripheral::Field<decltype(RCC->PLLCFGR), (1UL << 16), isob::peripheral::AccessMode::RW, 1, 2>
      PLLP{};
  static constexpr isob::peripheral::Field<decltype(RCC->PLLCFGR), (1UL << 6), isob::peripheral::AccessMode::RW, 1, 9>
      PLLN{};
  static constexpr isob::peripheral::Field<decltype(RCC->PLLCFGR), (1UL << 0), isob::peripheral::AccessMode::RW, 1, 6>
      PLLM{};
};

struct RCC_CFGR {
  static constexpr isob::peripheral::Field<decltype(RCC->CFGR), (1UL << 26), isob::peripheral::AccessMode::RW, 2, 3>
      MCO2{};
  static constexpr isob::peripheral::Field<decltype(RCC->CFGR), (1UL << 23), isob::peripheral::AccessMode::RW, 1>
      I2SSRC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CFGR), (1UL << 19), isob::peripheral::AccessMode::RW, 2, 2>
      MCO1{};
  static constexpr isob::peripheral::Field<decltype(RCC->CFGR), (1UL << 7), isob::peripheral::AccessMode::RW, 3, 3>
      PPRE{};
  static constexpr isob::peripheral::Field<decltype(RCC->CFGR), (1UL << 2), isob::peripheral::AccessMode::RW, 1, 2>
      SWS{};
  static constexpr isob::peripheral::Field<decltype(RCC->CFGR), (1UL << 0), isob::peripheral::AccessMode::RW, 1, 2>
      SW{};
};

struct RCC_CIR {
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 23), isob::peripheral::AccessMode::W, 1> CSSC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 21), isob::peripheral::AccessMode::W, 1>
      PLLI2SRDYC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 20), isob::peripheral::AccessMode::W, 1>
      PLLRDYC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 19), isob::peripheral::AccessMode::W, 1>
      HSERDYC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 18), isob::peripheral::AccessMode::W, 1>
      HSIRDYC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 17), isob::peripheral::AccessMode::W, 1>
      LSERDYC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 16), isob::peripheral::AccessMode::W, 1>
      LSIRDYC{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 13), isob::peripheral::AccessMode::W, 1>
      PLLI2SRDYIE{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 12), isob::peripheral::AccessMode::W, 1>
      PLLRDYIE{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 11), isob::peripheral::AccessMode::W, 1>
      HSERDYIE{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 10), isob::peripheral::AccessMode::W, 1>
      HSIRDYIE{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 9), isob::peripheral::AccessMode::W, 1>
      LSERDYIE{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 8), isob::peripheral::AccessMode::W, 1>
      LSIRDYIE{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 7), isob::peripheral::AccessMode::W, 1> CSSF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 5), isob::peripheral::AccessMode::W, 1>
      PLLI2SRDYF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 4), isob::peripheral::AccessMode::W, 1>
      PLLRDYF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 3), isob::peripheral::AccessMode::W, 1>
      HSERDYF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 2), isob::peripheral::AccessMode::W, 1>
      HSIRDYF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 1), isob::peripheral::AccessMode::W, 1>
      LSERDYF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CIR), (1UL << 0), isob::peripheral::AccessMode::W, 1>
      LSIRDYF{};
};

struct RCC_AHB1RSTR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 29), isob::peripheral::AccessMode::RW, 1>
      OTGHSRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 25), isob::peripheral::AccessMode::RW, 1>
      ETHMACRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 22), isob::peripheral::AccessMode::RW, 1>
      DMA2RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 21), isob::peripheral::AccessMode::RW, 1>
      DMA1RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 12), isob::peripheral::AccessMode::RW, 1>
      CRCRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      GPIOIRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      GPIOHRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      GPIOGRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      GPIOFRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      GPIOERST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 3), isob::peripheral::AccessMode::RW, 1>
      GPIODRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      GPIOCRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      GPIOBRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1RSTR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      GPIOARST{};
};

struct RCC_AHB2RSTR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2RSTR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      OTGFSRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2RSTR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      RNGRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2RSTR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      DCMIRST{};
};

struct RCC_AHB3RSTR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB3RSTR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      FSMCRST{};
};

struct RCC_APB1RSTR {
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 29), isob::peripheral::AccessMode::RW, 1>
      DACRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 28), isob::peripheral::AccessMode::RW, 1>
      PWRRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 26), isob::peripheral::AccessMode::RW, 1>
      CAN2RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 25), isob::peripheral::AccessMode::RW, 1>
      CAN1RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 23), isob::peripheral::AccessMode::RW, 1>
      I2C3RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 22), isob::peripheral::AccessMode::RW, 1>
      I2C2RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 21), isob::peripheral::AccessMode::RW, 1>
      I2C1RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 20), isob::peripheral::AccessMode::RW, 1>
      UART5RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 19), isob::peripheral::AccessMode::RW, 1>
      UART4RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      UART3RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 17), isob::peripheral::AccessMode::RW, 1>
      UART2RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 15), isob::peripheral::AccessMode::RW, 1>
      SPI3RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 14), isob::peripheral::AccessMode::RW, 1>
      SPI2RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 11), isob::peripheral::AccessMode::RW, 1>
      WWDGRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      TIM14RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      TIM13RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      TIM12RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      TIM7RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      TIM6RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 3), isob::peripheral::AccessMode::RW, 1>
      TIM5RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      TIM4RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      TIM3RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1RSTR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      TIM2RST{};
};

struct RCC_APB2RSTR {
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      TIM11RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 17), isob::peripheral::AccessMode::RW, 1>
      TIM10RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 16), isob::peripheral::AccessMode::RW, 1>
      TIM9RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 14), isob::peripheral::AccessMode::RW, 1>
      SYSCFGRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 12), isob::peripheral::AccessMode::RW, 1>
      SPI1RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 11), isob::peripheral::AccessMode::RW, 1>
      SDIORST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      ADCRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      USART6RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      USART1RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      TIM8RST{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2RSTR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      TIM1RST{};
};

struct RCC_AHB1ENR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 30), isob::peripheral::AccessMode::RW, 1>
      OTGHSULPIEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 29), isob::peripheral::AccessMode::RW, 1>
      OTGHSEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 28), isob::peripheral::AccessMode::RW, 1>
      ETHMACPTPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 27), isob::peripheral::AccessMode::RW, 1>
      ETHMACRXEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 26), isob::peripheral::AccessMode::RW, 1>
      ETHMACTXEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 25), isob::peripheral::AccessMode::RW, 1>
      ETHMACEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 22), isob::peripheral::AccessMode::RW, 1>
      DMA2EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 21), isob::peripheral::AccessMode::RW, 1>
      DMA1EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      BKPSRAMEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 12), isob::peripheral::AccessMode::RW, 1>
      CRCEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      GPIOIEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      GPIOHEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      GPIOGEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      GPIOFEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      GPIOEEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 3), isob::peripheral::AccessMode::RW, 1>
      GPIODEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      GPIOCEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      GPIOBEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1ENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      GPIOAEN{};
};

struct RCC_AHB2ENR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2ENR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      OTGFSEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2ENR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      RNGEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2ENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      DCMIEN{};
};

struct RCC_AHB3ENR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB3ENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      FSMCEN{};
};

struct RCC_APB1ENR {
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 29), isob::peripheral::AccessMode::RW, 1>
      DACEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 28), isob::peripheral::AccessMode::RW, 1>
      PWREN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 26), isob::peripheral::AccessMode::RW, 1>
      CAN2EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 25), isob::peripheral::AccessMode::RW, 1>
      CAN1EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 23), isob::peripheral::AccessMode::RW, 1>
      I2C3EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 22), isob::peripheral::AccessMode::RW, 1>
      I2C2EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 21), isob::peripheral::AccessMode::RW, 1>
      I2C1EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 20), isob::peripheral::AccessMode::RW, 1>
      UART5EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 19), isob::peripheral::AccessMode::RW, 1>
      UART4EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      USART3EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 17), isob::peripheral::AccessMode::RW, 1>
      USART2EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 15), isob::peripheral::AccessMode::RW, 1>
      SPI3EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 14), isob::peripheral::AccessMode::RW, 1>
      SPI2EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 11), isob::peripheral::AccessMode::RW, 1>
      WWDGEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      TIM14EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      TIM13EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      TIM12EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      TIM7EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      TIM6EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 3), isob::peripheral::AccessMode::RW, 1>
      TIM5EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      TIM4EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      TIM3EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1ENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      TIM2EN{};
};

struct RCC_APB2ENR {
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      TIM11EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 17), isob::peripheral::AccessMode::RW, 1>
      TIM10EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 16), isob::peripheral::AccessMode::RW, 1>
      TIM9EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 14), isob::peripheral::AccessMode::RW, 1>
      SYSCFGEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 12), isob::peripheral::AccessMode::RW, 1>
      SPI1EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 11), isob::peripheral::AccessMode::RW, 1>
      SDIOEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 10), isob::peripheral::AccessMode::RW, 1>
      ADC3EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 9), isob::peripheral::AccessMode::RW, 1>
      ADC2EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      ADC1EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      USART6EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      USART1EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      TIM8EN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2ENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      TIM1EN{};
};

struct RCC_AHB1LPENR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 30), isob::peripheral::AccessMode::RW, 1>
      OTGHSULPILPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 29), isob::peripheral::AccessMode::RW, 1>
      OTGHSLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 28), isob::peripheral::AccessMode::RW, 1>
      ETHMACPTPLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 27), isob::peripheral::AccessMode::RW, 1>
      ETHMACRXLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 26), isob::peripheral::AccessMode::RW, 1>
      ETHMACTXLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 25), isob::peripheral::AccessMode::RW, 1>
      ETHMACLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 22), isob::peripheral::AccessMode::RW, 1>
      DMA2LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 21), isob::peripheral::AccessMode::RW, 1>
      DMA1LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      BKPSRAMLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 17), isob::peripheral::AccessMode::RW, 1>
      SRAM2LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 16), isob::peripheral::AccessMode::RW, 1>
      SRAM1LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 15), isob::peripheral::AccessMode::RW, 1>
      FLITFLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 12), isob::peripheral::AccessMode::RW, 1>
      CRCLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      GPIOILPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      GPIOHLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      GPIOGLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      GPIOFLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      GPIOELPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 3), isob::peripheral::AccessMode::RW, 1>
      GPIODLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      GPIOCLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      GPIOBLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB1LPENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      GPIOALPEN{};
};

struct RCC_AHB2LPENR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2LPENR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      OTGFSLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2LPENR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      RNGLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->AHB2LPENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      DCMILPEN{};
};

struct RCC_AHB3LPENR {
  static constexpr isob::peripheral::Field<decltype(RCC->AHB3LPENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      FSMCLPEN{};
};

struct RCC_APB1LPENR {
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 29), isob::peripheral::AccessMode::RW, 1>
      DACLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 28), isob::peripheral::AccessMode::RW, 1>
      PWRLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 26), isob::peripheral::AccessMode::RW, 1>
      CAN2LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 25), isob::peripheral::AccessMode::RW, 1>
      CAN1LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 23), isob::peripheral::AccessMode::RW, 1>
      I2C3LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 22), isob::peripheral::AccessMode::RW, 1>
      I2C2LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 21), isob::peripheral::AccessMode::RW, 1>
      I2C1LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 20), isob::peripheral::AccessMode::RW, 1>
      UART5LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 19), isob::peripheral::AccessMode::RW, 1>
      UART4LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      USART3LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 17), isob::peripheral::AccessMode::RW, 1>
      USART2LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 15), isob::peripheral::AccessMode::RW, 1>
      SPI3LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 14), isob::peripheral::AccessMode::RW, 1>
      SPI2LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 11), isob::peripheral::AccessMode::RW, 1>
      WWDGLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      TIM14LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 7), isob::peripheral::AccessMode::RW, 1>
      TIM13LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 6), isob::peripheral::AccessMode::RW, 1>
      TIM12LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      TIM7LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      TIM6LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 3), isob::peripheral::AccessMode::RW, 1>
      TIM5LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      TIM4LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      TIM3LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB1LPENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      TIM2LPEN{};
};

struct RCC_APB2LPENR {
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 18), isob::peripheral::AccessMode::RW, 1>
      TIM11LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 17), isob::peripheral::AccessMode::RW, 1>
      TIM10LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 16), isob::peripheral::AccessMode::RW, 1>
      TIM9LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 14), isob::peripheral::AccessMode::RW, 1>
      SYSCFGLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 12), isob::peripheral::AccessMode::RW, 1>
      SPI1LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 11), isob::peripheral::AccessMode::RW, 1>
      SDIOLPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 10), isob::peripheral::AccessMode::RW, 1>
      ADC3LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 9), isob::peripheral::AccessMode::RW, 1>
      ADC2LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 8), isob::peripheral::AccessMode::RW, 1>
      ADC1LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 5), isob::peripheral::AccessMode::RW, 1>
      USART6LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 4), isob::peripheral::AccessMode::RW, 1>
      USART1LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      TIM8LPEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->APB2LPENR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      TIM1LPEN{};
};

struct RCC_BDCR {
  static constexpr isob::peripheral::Field<decltype(RCC->BDCR), (1UL << 16), isob::peripheral::AccessMode::RW, 1>
      BDRST{};
  static constexpr isob::peripheral::Field<decltype(RCC->BDCR), (1UL << 15), isob::peripheral::AccessMode::RW, 1>
      RTCEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->BDCR), (1UL << 8), isob::peripheral::AccessMode::RW, 1, 2>
      RTCSEL{};
  static constexpr isob::peripheral::Field<decltype(RCC->BDCR), (1UL << 2), isob::peripheral::AccessMode::RW, 1>
      LSEBYP{};
  static constexpr isob::peripheral::Field<decltype(RCC->BDCR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      LSERDY{};
  static constexpr isob::peripheral::Field<decltype(RCC->BDCR), (1UL << 0), isob::peripheral::AccessMode::RW, 1>
      LSEON{};
};

struct RCC_CSR {
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 31), isob::peripheral::AccessMode::RW, 1>
      LPWRRSTF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 30), isob::peripheral::AccessMode::RW, 1>
      WWDGRSTF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 29), isob::peripheral::AccessMode::RW, 1>
      WDGRSTF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 28), isob::peripheral::AccessMode::RW, 1>
      SFTRSTF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 27), isob::peripheral::AccessMode::RW, 1>
      PORRSTF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 26), isob::peripheral::AccessMode::RW, 1>
      PADRSTF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 25), isob::peripheral::AccessMode::RW, 1>
      BORRSTF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 24), isob::peripheral::AccessMode::RW, 1> RMVF{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 1), isob::peripheral::AccessMode::RW, 1>
      LSIRDY{};
  static constexpr isob::peripheral::Field<decltype(RCC->CSR), (1UL << 0), isob::peripheral::AccessMode::RW, 1> LSION{};
};

struct RCC_SSCGR {
  static constexpr isob::peripheral::Field<decltype(RCC->SSCGR), (1UL << 31), isob::peripheral::AccessMode::RW, 1>
      SSCGEN{};
  static constexpr isob::peripheral::Field<decltype(RCC->SSCGR), (1UL << 30), isob::peripheral::AccessMode::RW, 1>
      SPREADSEL{};
  static constexpr isob::peripheral::Field<decltype(RCC->SSCGR), (1UL << 13), isob::peripheral::AccessMode::RW, 15>
      INCSTEP{};
  static constexpr isob::peripheral::Field<decltype(RCC->SSCGR), (1UL << 0), isob::peripheral::AccessMode::RW, 13>
      MODPER{};
};

struct RCC_PLLI2SCFGR {
  static constexpr isob::peripheral::Field<decltype(RCC->PLLI2SCFGR), (1UL << 28), isob::peripheral::AccessMode::RW, 3>
      PLLI2SRx{};
  static constexpr isob::peripheral::Field<decltype(RCC->PLLI2SCFGR), (1UL << 6), isob::peripheral::AccessMode::RW, 9>
      PLLI2SNx{};
};

} // namespace stm32f407::rcc
