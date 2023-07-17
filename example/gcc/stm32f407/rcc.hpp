#pragma once

#include "register.hpp"

namespace stm32f407::rcc {

template <const cpp_register::RegisterAddress address> struct RCC_T {
  static constexpr cpp_register::Register<address + 0x0, cpp_register::AccessMode::R, uint32_t, struct CR> CR{};
  static constexpr cpp_register::Register<address + 0x4, cpp_register::AccessMode::RW, uint32_t, struct PLLCFGR> PLLCFGR{};
  static constexpr cpp_register::Register<address + 0x8, cpp_register::AccessMode::RW, uint32_t, struct CFGR> CFGR{};
  static constexpr cpp_register::Register<address + 0xC, cpp_register::AccessMode::W, uint32_t, struct CIR> CIR{};
  static constexpr cpp_register::Register<address + 0x10, cpp_register::AccessMode::RW, uint32_t, struct AHB1RSTR> AHB1RSTR{};
  static constexpr cpp_register::Register<address + 0x14, cpp_register::AccessMode::RW, uint32_t, struct AHB2RSTR> AHB2RSTR{};
  static constexpr cpp_register::Register<address + 0x18, cpp_register::AccessMode::RW, uint32_t, struct AHB3RSTR> AHB3RSTR{};
  static constexpr cpp_register::Register<address + 0x20, cpp_register::AccessMode::RW, uint32_t, struct APB1RSTR> APB1RSTR{};
  static constexpr cpp_register::Register<address + 0x24, cpp_register::AccessMode::RW, uint32_t, struct APB2RSTR> APB2RSTR{};
  static constexpr cpp_register::Register<address + 0x30, cpp_register::AccessMode::RW, uint32_t, struct AHB1ENR> AHB1ENR{};
  static constexpr cpp_register::Register<address + 0x34, cpp_register::AccessMode::RW, uint32_t, struct AHB2ENR> AHB2ENR{};
  static constexpr cpp_register::Register<address + 0x38, cpp_register::AccessMode::RW, uint32_t, struct AHB3ENR> AHB3ENR{};
  static constexpr cpp_register::Register<address + 0x40, cpp_register::AccessMode::RW, uint32_t, struct APB1ENR> APB1ENR{};
  static constexpr cpp_register::Register<address + 0x44, cpp_register::AccessMode::RW, uint32_t, struct APB2ENR> APB2ENR{};
  static constexpr cpp_register::Register<address + 0x50, cpp_register::AccessMode::RW, uint32_t, struct AHB1LPENR> AHB1LPENR{};
  static constexpr cpp_register::Register<address + 0x54, cpp_register::AccessMode::RW, uint32_t, struct AHB2LPENR> AHB2LPENR{};
  static constexpr cpp_register::Register<address + 0x58, cpp_register::AccessMode::RW, uint32_t, struct AHB3LPENR> AHB3LPENR{};
  static constexpr cpp_register::Register<address + 0x60, cpp_register::AccessMode::RW, uint32_t, struct APB1LPENR> APB1LPENR{};
  static constexpr cpp_register::Register<address + 0x64, cpp_register::AccessMode::RW, uint32_t, struct APB2LPENR> APB2LPENR{};
  static constexpr cpp_register::Register<address + 0x70, cpp_register::AccessMode::RW, uint32_t, struct BDCR> BDCR{};
  static constexpr cpp_register::Register<address + 0x74, cpp_register::AccessMode::RW, uint32_t, struct CSR> CSR{};
  static constexpr cpp_register::Register<address + 0x80, cpp_register::AccessMode::RW, uint32_t, struct SSCGR> SSCGR{};
  static constexpr cpp_register::Register<address + 0x84, cpp_register::AccessMode::RW, uint32_t, struct PLLI2SCFGR> PLLI2SCFGR{};
};

inline constexpr RCC_T<0x40023800> const *RCC{};

struct RCC_CR {
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 27), cpp_register::AccessMode::R, 1> PLLI2SRDY{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 26), cpp_register::AccessMode::R, 1> PLLI2SON{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 25), cpp_register::AccessMode::R, 1> PLLRDY{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 24), cpp_register::AccessMode::R, 1> PLLON{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 19), cpp_register::AccessMode::R, 1> CSSON{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 18), cpp_register::AccessMode::R, 1> HSEBYP{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 17), cpp_register::AccessMode::R, 1> HSERDY{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 16), cpp_register::AccessMode::R, 1> HSEON{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 8), cpp_register::AccessMode::R, 8> HSICAL{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 3), cpp_register::AccessMode::R, 5> HSITRIM{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 1), cpp_register::AccessMode::R, 1> HSIRDY{};
  static constexpr cpp_register::Field<decltype(RCC->CR), (1UL << 0), cpp_register::AccessMode::R, 1> HSION{};
};

struct RCC_PLLCFGR {
  static constexpr cpp_register::Field<decltype(RCC->PLLCFGR), (1UL << 24), cpp_register::AccessMode::RW, 1, 4> PLLQ{};
  static constexpr cpp_register::Field<decltype(RCC->PLLCFGR), (1UL << 22), cpp_register::AccessMode::RW, 1> PLLSRC{};
  static constexpr cpp_register::Field<decltype(RCC->PLLCFGR), (1UL << 16), cpp_register::AccessMode::RW, 1, 2> PLLP{};
  static constexpr cpp_register::Field<decltype(RCC->PLLCFGR), (1UL << 6), cpp_register::AccessMode::RW, 1, 9> PLLN{};
  static constexpr cpp_register::Field<decltype(RCC->PLLCFGR), (1UL << 0), cpp_register::AccessMode::RW, 1, 6> PLLM{};
};

struct RCC_CFGR {
  static constexpr cpp_register::Field<decltype(RCC->CFGR), (1UL << 26), cpp_register::AccessMode::RW, 2, 3> MCO2{};
  static constexpr cpp_register::Field<decltype(RCC->CFGR), (1UL << 23), cpp_register::AccessMode::RW, 1> I2SSRC{};
  static constexpr cpp_register::Field<decltype(RCC->CFGR), (1UL << 19), cpp_register::AccessMode::RW, 2, 2> MCO1{};
  static constexpr cpp_register::Field<decltype(RCC->CFGR), (1UL << 7), cpp_register::AccessMode::RW, 3, 3> PPRE{};
  static constexpr cpp_register::Field<decltype(RCC->CFGR), (1UL << 2), cpp_register::AccessMode::RW, 1, 2> SWS{};
  static constexpr cpp_register::Field<decltype(RCC->CFGR), (1UL << 0), cpp_register::AccessMode::RW, 1, 2> SW{};
};

struct RCC_CIR {
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 23), cpp_register::AccessMode::W, 1> CSSC{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 21), cpp_register::AccessMode::W, 1> PLLI2SRDYC{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 20), cpp_register::AccessMode::W, 1> PLLRDYC{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 19), cpp_register::AccessMode::W, 1> HSERDYC{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 18), cpp_register::AccessMode::W, 1> HSIRDYC{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 17), cpp_register::AccessMode::W, 1> LSERDYC{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 16), cpp_register::AccessMode::W, 1> LSIRDYC{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 13), cpp_register::AccessMode::W, 1> PLLI2SRDYIE{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 12), cpp_register::AccessMode::W, 1> PLLRDYIE{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 11), cpp_register::AccessMode::W, 1> HSERDYIE{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 10), cpp_register::AccessMode::W, 1> HSIRDYIE{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 9), cpp_register::AccessMode::W, 1> LSERDYIE{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 8), cpp_register::AccessMode::W, 1> LSIRDYIE{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 7), cpp_register::AccessMode::W, 1> CSSF{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 5), cpp_register::AccessMode::W, 1> PLLI2SRDYF{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 4), cpp_register::AccessMode::W, 1> PLLRDYF{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 3), cpp_register::AccessMode::W, 1> HSERDYF{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 2), cpp_register::AccessMode::W, 1> HSIRDYF{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 1), cpp_register::AccessMode::W, 1> LSERDYF{};
  static constexpr cpp_register::Field<decltype(RCC->CIR), (1UL << 0), cpp_register::AccessMode::W, 1> LSIRDYF{};
};

struct RCC_AHB1RSTR {
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 29), cpp_register::AccessMode::RW, 1> OTGHSRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 25), cpp_register::AccessMode::RW, 1> ETHMACRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 22), cpp_register::AccessMode::RW, 1> DMA2RST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 21), cpp_register::AccessMode::RW, 1> DMA1RST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 12), cpp_register::AccessMode::RW, 1> CRCRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 8), cpp_register::AccessMode::RW, 1> GPIOIRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 7), cpp_register::AccessMode::RW, 1> GPIOHRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 6), cpp_register::AccessMode::RW, 1> GPIOGRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 5), cpp_register::AccessMode::RW, 1> GPIOFRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 4), cpp_register::AccessMode::RW, 1> GPIOERST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 3), cpp_register::AccessMode::RW, 1> GPIODRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 2), cpp_register::AccessMode::RW, 1> GPIOCRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 1), cpp_register::AccessMode::RW, 1> GPIOBRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1RSTR), (1UL << 0), cpp_register::AccessMode::RW, 1> GPIOARST{};
};

struct RCC_AHB2RSTR {
  static constexpr cpp_register::Field<decltype(RCC->AHB2RSTR), (1UL << 7), cpp_register::AccessMode::RW, 1> OTGFSRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB2RSTR), (1UL << 6), cpp_register::AccessMode::RW, 1> RNGRST{};
  static constexpr cpp_register::Field<decltype(RCC->AHB2RSTR), (1UL << 0), cpp_register::AccessMode::RW, 1> DCMIRST{};
};

struct RCC_AHB3RSTR {
  static constexpr cpp_register::Field<decltype(RCC->AHB3RSTR), (1UL << 0), cpp_register::AccessMode::RW, 1> FSMCRST{};
};

struct RCC_APB1RSTR {
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 29), cpp_register::AccessMode::RW, 1> DACRST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 28), cpp_register::AccessMode::RW, 1> PWRRST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 26), cpp_register::AccessMode::RW, 1> CAN2RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 25), cpp_register::AccessMode::RW, 1> CAN1RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 23), cpp_register::AccessMode::RW, 1> I2C3RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 22), cpp_register::AccessMode::RW, 1> I2C2RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 21), cpp_register::AccessMode::RW, 1> I2C1RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 20), cpp_register::AccessMode::RW, 1> UART5RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 19), cpp_register::AccessMode::RW, 1> UART4RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 18), cpp_register::AccessMode::RW, 1> UART3RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 17), cpp_register::AccessMode::RW, 1> UART2RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 15), cpp_register::AccessMode::RW, 1> SPI3RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 14), cpp_register::AccessMode::RW, 1> SPI2RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 11), cpp_register::AccessMode::RW, 1> WWDGRST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 8), cpp_register::AccessMode::RW, 1> TIM14RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 7), cpp_register::AccessMode::RW, 1> TIM13RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 6), cpp_register::AccessMode::RW, 1> TIM12RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 5), cpp_register::AccessMode::RW, 1> TIM7RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 4), cpp_register::AccessMode::RW, 1> TIM6RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 3), cpp_register::AccessMode::RW, 1> TIM5RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 2), cpp_register::AccessMode::RW, 1> TIM4RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 1), cpp_register::AccessMode::RW, 1> TIM3RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB1RSTR), (1UL << 0), cpp_register::AccessMode::RW, 1> TIM2RST{};
};

struct RCC_APB2RSTR {
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 18), cpp_register::AccessMode::RW, 1> TIM11RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 17), cpp_register::AccessMode::RW, 1> TIM10RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 16), cpp_register::AccessMode::RW, 1> TIM9RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 14), cpp_register::AccessMode::RW, 1> SYSCFGRST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 12), cpp_register::AccessMode::RW, 1> SPI1RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 11), cpp_register::AccessMode::RW, 1> SDIORST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 8), cpp_register::AccessMode::RW, 1> ADCRST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 5), cpp_register::AccessMode::RW, 1> USART6RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 4), cpp_register::AccessMode::RW, 1> USART1RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 1), cpp_register::AccessMode::RW, 1> TIM8RST{};
  static constexpr cpp_register::Field<decltype(RCC->APB2RSTR), (1UL << 0), cpp_register::AccessMode::RW, 1> TIM1RST{};
};

struct RCC_AHB1ENR {
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 30), cpp_register::AccessMode::RW, 1> OTGHSULPIEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 29), cpp_register::AccessMode::RW, 1> OTGHSEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 28), cpp_register::AccessMode::RW, 1> ETHMACPTPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 27), cpp_register::AccessMode::RW, 1> ETHMACRXEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 26), cpp_register::AccessMode::RW, 1> ETHMACTXEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 25), cpp_register::AccessMode::RW, 1> ETHMACEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 22), cpp_register::AccessMode::RW, 1> DMA2EN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 21), cpp_register::AccessMode::RW, 1> DMA1EN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 18), cpp_register::AccessMode::RW, 1> BKPSRAMEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 12), cpp_register::AccessMode::RW, 1> CRCEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 8), cpp_register::AccessMode::RW, 1> GPIOIEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 7), cpp_register::AccessMode::RW, 1> GPIOHEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 6), cpp_register::AccessMode::RW, 1> GPIOGEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 5), cpp_register::AccessMode::RW, 1> GPIOFEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 4), cpp_register::AccessMode::RW, 1> GPIOEEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 3), cpp_register::AccessMode::RW, 1> GPIODEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 2), cpp_register::AccessMode::RW, 1> GPIOCEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 1), cpp_register::AccessMode::RW, 1> GPIOBEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1ENR), (1UL << 0), cpp_register::AccessMode::RW, 1> GPIOAEN{};
};

struct RCC_AHB2ENR {
  static constexpr cpp_register::Field<decltype(RCC->AHB2ENR), (1UL << 7), cpp_register::AccessMode::RW, 1> OTGFSEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB2ENR), (1UL << 6), cpp_register::AccessMode::RW, 1> RNGEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB2ENR), (1UL << 0), cpp_register::AccessMode::RW, 1> DCMIEN{};
};

struct RCC_AHB3ENR {
  static constexpr cpp_register::Field<decltype(RCC->AHB3ENR), (1UL << 0), cpp_register::AccessMode::RW, 1> FSMCEN{};
};

struct RCC_APB1ENR {
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 29), cpp_register::AccessMode::RW, 1> DACEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 28), cpp_register::AccessMode::RW, 1> PWREN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 26), cpp_register::AccessMode::RW, 1> CAN2EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 25), cpp_register::AccessMode::RW, 1> CAN1EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 23), cpp_register::AccessMode::RW, 1> I2C3EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 22), cpp_register::AccessMode::RW, 1> I2C2EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 21), cpp_register::AccessMode::RW, 1> I2C1EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 20), cpp_register::AccessMode::RW, 1> UART5EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 19), cpp_register::AccessMode::RW, 1> UART4EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 18), cpp_register::AccessMode::RW, 1> USART3EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 17), cpp_register::AccessMode::RW, 1> USART2EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 15), cpp_register::AccessMode::RW, 1> SPI3EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 14), cpp_register::AccessMode::RW, 1> SPI2EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 11), cpp_register::AccessMode::RW, 1> WWDGEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 8), cpp_register::AccessMode::RW, 1> TIM14EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 7), cpp_register::AccessMode::RW, 1> TIM13EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 6), cpp_register::AccessMode::RW, 1> TIM12EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 5), cpp_register::AccessMode::RW, 1> TIM7EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 4), cpp_register::AccessMode::RW, 1> TIM6EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 3), cpp_register::AccessMode::RW, 1> TIM5EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 2), cpp_register::AccessMode::RW, 1> TIM4EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 1), cpp_register::AccessMode::RW, 1> TIM3EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1ENR), (1UL << 0), cpp_register::AccessMode::RW, 1> TIM2EN{};
};

struct RCC_APB2ENR {
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 18), cpp_register::AccessMode::RW, 1> TIM11EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 17), cpp_register::AccessMode::RW, 1> TIM10EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 16), cpp_register::AccessMode::RW, 1> TIM9EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 14), cpp_register::AccessMode::RW, 1> SYSCFGEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 12), cpp_register::AccessMode::RW, 1> SPI1EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 11), cpp_register::AccessMode::RW, 1> SDIOEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 10), cpp_register::AccessMode::RW, 1> ADC3EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 9), cpp_register::AccessMode::RW, 1> ADC2EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 8), cpp_register::AccessMode::RW, 1> ADC1EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 5), cpp_register::AccessMode::RW, 1> USART6EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 4), cpp_register::AccessMode::RW, 1> USART1EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 1), cpp_register::AccessMode::RW, 1> TIM8EN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2ENR), (1UL << 0), cpp_register::AccessMode::RW, 1> TIM1EN{};
};

struct RCC_AHB1LPENR {
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 30), cpp_register::AccessMode::RW, 1> OTGHSULPILPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 29), cpp_register::AccessMode::RW, 1> OTGHSLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 28), cpp_register::AccessMode::RW, 1> ETHMACPTPLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 27), cpp_register::AccessMode::RW, 1> ETHMACRXLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 26), cpp_register::AccessMode::RW, 1> ETHMACTXLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 25), cpp_register::AccessMode::RW, 1> ETHMACLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 22), cpp_register::AccessMode::RW, 1> DMA2LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 21), cpp_register::AccessMode::RW, 1> DMA1LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 18), cpp_register::AccessMode::RW, 1> BKPSRAMLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 17), cpp_register::AccessMode::RW, 1> SRAM2LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 16), cpp_register::AccessMode::RW, 1> SRAM1LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 15), cpp_register::AccessMode::RW, 1> FLITFLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 12), cpp_register::AccessMode::RW, 1> CRCLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 8), cpp_register::AccessMode::RW, 1> GPIOILPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 7), cpp_register::AccessMode::RW, 1> GPIOHLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 6), cpp_register::AccessMode::RW, 1> GPIOGLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 5), cpp_register::AccessMode::RW, 1> GPIOFLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 4), cpp_register::AccessMode::RW, 1> GPIOELPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 3), cpp_register::AccessMode::RW, 1> GPIODLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 2), cpp_register::AccessMode::RW, 1> GPIOCLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 1), cpp_register::AccessMode::RW, 1> GPIOBLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB1LPENR), (1UL << 0), cpp_register::AccessMode::RW, 1> GPIOALPEN{};
};

struct RCC_AHB2LPENR {
  static constexpr cpp_register::Field<decltype(RCC->AHB2LPENR), (1UL << 7), cpp_register::AccessMode::RW, 1> OTGFSLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB2LPENR), (1UL << 6), cpp_register::AccessMode::RW, 1> RNGLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->AHB2LPENR), (1UL << 0), cpp_register::AccessMode::RW, 1> DCMILPEN{};
};

struct RCC_AHB3LPENR {
  static constexpr cpp_register::Field<decltype(RCC->AHB3LPENR), (1UL << 0), cpp_register::AccessMode::RW, 1> FSMCLPEN{};
};

struct RCC_APB1LPENR {
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 29), cpp_register::AccessMode::RW, 1> DACLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 28), cpp_register::AccessMode::RW, 1> PWRLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 26), cpp_register::AccessMode::RW, 1> CAN2LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 25), cpp_register::AccessMode::RW, 1> CAN1LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 23), cpp_register::AccessMode::RW, 1> I2C3LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 22), cpp_register::AccessMode::RW, 1> I2C2LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 21), cpp_register::AccessMode::RW, 1> I2C1LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 20), cpp_register::AccessMode::RW, 1> UART5LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 19), cpp_register::AccessMode::RW, 1> UART4LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 18), cpp_register::AccessMode::RW, 1> USART3LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 17), cpp_register::AccessMode::RW, 1> USART2LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 15), cpp_register::AccessMode::RW, 1> SPI3LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 14), cpp_register::AccessMode::RW, 1> SPI2LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 11), cpp_register::AccessMode::RW, 1> WWDGLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 8), cpp_register::AccessMode::RW, 1> TIM14LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 7), cpp_register::AccessMode::RW, 1> TIM13LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 6), cpp_register::AccessMode::RW, 1> TIM12LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 5), cpp_register::AccessMode::RW, 1> TIM7LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 4), cpp_register::AccessMode::RW, 1> TIM6LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 3), cpp_register::AccessMode::RW, 1> TIM5LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 2), cpp_register::AccessMode::RW, 1> TIM4LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 1), cpp_register::AccessMode::RW, 1> TIM3LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB1LPENR), (1UL << 0), cpp_register::AccessMode::RW, 1> TIM2LPEN{};
};

struct RCC_APB2LPENR {
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 18), cpp_register::AccessMode::RW, 1> TIM11LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 17), cpp_register::AccessMode::RW, 1> TIM10LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 16), cpp_register::AccessMode::RW, 1> TIM9LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 14), cpp_register::AccessMode::RW, 1> SYSCFGLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 12), cpp_register::AccessMode::RW, 1> SPI1LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 11), cpp_register::AccessMode::RW, 1> SDIOLPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 10), cpp_register::AccessMode::RW, 1> ADC3LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 9), cpp_register::AccessMode::RW, 1> ADC2LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 8), cpp_register::AccessMode::RW, 1> ADC1LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 5), cpp_register::AccessMode::RW, 1> USART6LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 4), cpp_register::AccessMode::RW, 1> USART1LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 1), cpp_register::AccessMode::RW, 1> TIM8LPEN{};
  static constexpr cpp_register::Field<decltype(RCC->APB2LPENR), (1UL << 0), cpp_register::AccessMode::RW, 1> TIM1LPEN{};
};

struct RCC_BDCR {
  static constexpr cpp_register::Field<decltype(RCC->BDCR), (1UL << 16), cpp_register::AccessMode::RW, 1> BDRST{};
  static constexpr cpp_register::Field<decltype(RCC->BDCR), (1UL << 15), cpp_register::AccessMode::RW, 1> RTCEN{};
  static constexpr cpp_register::Field<decltype(RCC->BDCR), (1UL << 8), cpp_register::AccessMode::RW, 1, 2> RTCSEL{};
  static constexpr cpp_register::Field<decltype(RCC->BDCR), (1UL << 2), cpp_register::AccessMode::RW, 1> LSEBYP{};
  static constexpr cpp_register::Field<decltype(RCC->BDCR), (1UL << 1), cpp_register::AccessMode::RW, 1> LSERDY{};
  static constexpr cpp_register::Field<decltype(RCC->BDCR), (1UL << 0), cpp_register::AccessMode::RW, 1> LSEON{};
};

struct RCC_CSR {
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 31), cpp_register::AccessMode::RW, 1> LPWRRSTF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 30), cpp_register::AccessMode::RW, 1> WWDGRSTF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 29), cpp_register::AccessMode::RW, 1> WDGRSTF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 28), cpp_register::AccessMode::RW, 1> SFTRSTF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 27), cpp_register::AccessMode::RW, 1> PORRSTF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 26), cpp_register::AccessMode::RW, 1> PADRSTF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 25), cpp_register::AccessMode::RW, 1> BORRSTF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 24), cpp_register::AccessMode::RW, 1> RMVF{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 1), cpp_register::AccessMode::RW, 1> LSIRDY{};
  static constexpr cpp_register::Field<decltype(RCC->CSR), (1UL << 0), cpp_register::AccessMode::RW, 1> LSION{};
};

struct RCC_SSCGR {
  static constexpr cpp_register::Field<decltype(RCC->SSCGR), (1UL << 31), cpp_register::AccessMode::RW, 1> SSCGEN{};
  static constexpr cpp_register::Field<decltype(RCC->SSCGR), (1UL << 30), cpp_register::AccessMode::RW, 1> SPREADSEL{};
  static constexpr cpp_register::Field<decltype(RCC->SSCGR), (1UL << 13), cpp_register::AccessMode::RW, 15> INCSTEP{};
  static constexpr cpp_register::Field<decltype(RCC->SSCGR), (1UL << 0), cpp_register::AccessMode::RW, 13> MODPER{};
};

struct RCC_PLLI2SCFGR {
  static constexpr cpp_register::Field<decltype(RCC->PLLI2SCFGR), (1UL << 28), cpp_register::AccessMode::RW, 3> PLLI2SRx{};
  static constexpr cpp_register::Field<decltype(RCC->PLLI2SCFGR), (1UL << 6), cpp_register::AccessMode::RW, 9> PLLI2SNx{};
};

} // namespace stm32f407::rcc
