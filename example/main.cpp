#include "stm32f407.hpp"

using namespace peripheral;
using namespace stm32f407::registers::rcc;
using namespace stm32f407::registers::gpio;
using namespace stm32f407::registers::system_tick;

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

  SYST->RVR = SYST_RVR::RELOAD(SYST_PERIOD);
  SYST->CVR = SYST_CVR::CURRENT(SYST_PERIOD);
  SYST->CSR |= (SYST_CSR::CLKSOURCE | SYST_CSR::ENABLE);

  while (true) {
    if (SYST->CSR & SYST_CSR::COUNTFLAG) {
      GPIOD->ODR ^= GPIO_ODR::ODR[NUM_12] | GPIO_ODR::ODR[NUM_13] | GPIO_ODR::ODR[NUM_14] | GPIO_ODR::ODR[NUM_15];
    }
  }
}
