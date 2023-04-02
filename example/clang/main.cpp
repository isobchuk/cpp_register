#include "gpio.hpp"
#include "rcc.hpp"
#include "stk.hpp"

using namespace isob::peripheral;
using namespace stm32f407::rcc;
using namespace stm32f407::gpio;
using namespace stm32f407::stk;

[[noreturn]] int main();
extern "C" [[noreturn]] void Reset_Handler();

[[noreturn]] void Reset_Handler() { main(); }

[[gnu::used, gnu::section(".isr_vector")]] static constexpr void (*const g_pfnVectors[])(void) = {Reset_Handler};

[[noreturn]] int main() {
  static constexpr auto SYSTEM_MHZ = 16UL;
  static constexpr auto SYST_PERIOD = ConstVal<(SYSTEM_MHZ * 1000000UL) - 1>{};

  RCC->AHB1ENR |= RCC_AHB1ENR::GPIODEN;
  // GPIOD->MODER |= (GPIO_MODER::MODER[NUM_12](NUM_0) | GPIO_MODER::MODER[NUM_13](NUM_0) |
  // GPIO_MODER::MODER[NUM_14](NUM_0) | GPIO_MODER::MODER[NUM_15](NUM_0));

  GPIOD->MODER |= GPIO_MODER::MODER[NUM_12 | NUM_13 | NUM_14 | NUM_15](NUM_0);

  STK->LOAD = STK_LOAD::RELOAD(SYST_PERIOD);
  STK->VAL = STK_VAL::CURRENT(SYST_PERIOD);
  STK->CTRL |= (STK_CTRL::CLKSOURCE | STK_CTRL::ENABLE);

  while (true) {
    if (STK->CTRL & STK_CTRL::COUNTFLAG) {
      GPIOD->ODR ^= GPIO_ODR::ODR[NUM_12 | NUM_13 | NUM_14 | NUM_15];
    }
  }
}
