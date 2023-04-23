# cpp_register - safe, no-cost and easy-to-use Cpp header to work with HW registers

Metaprogrammed header to work safely with MCU registers without any influence to run-time (for Cortex-M3/M4 even more effective than plain C) that as written with templates, constexpr objects, static_assert, overloading and a bit of SFINAE.

Basic compile-time checks:

- Does the register contain this field?
- Access mode for both registers and fields (more than ten for now)
- Size of value to write to the register
- et cetera

## **Advantages**

1. Extended compile-time checks for the registers and fields ownership, size, access, overflowing, et cetera
2. As effective (size and speed) as the standard C CMSIS (in the some particular cases even more effective).
3. Writing several fields in the one register.
4. Cast from constexpr values to field values (without loosing security) for the integration to the driver level abstractions.
5. Automated bit-band to increase speed and reduce size.
6. Mimic to traditional CMSIS patterns (easy-to-use) with some improvements.
7. Short and easy-to-read form for the multi-field writing.
8. The most of errors can be seen during code writing (IntelliSense)
9. Work in the strict environment (-Werror, -Weverything, et cetera)
10. Cross-platform and cross-environment.
11. Support dynamic writing for the operations that are really needed it.

## **Description**

### **Abstract**

CMSIS files from the chip-makers is the common way to work with MCUs on the low-level.
However, these files have one big problem - it is unsafety.

Short example below show this:

```cpp
//Example for stm32f407 gpio

//ERROR: Wanted to give clock for GPIOD - mismatch with the register
RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
....
//ERROR: Try to write to the read-only register
GPIOD->IDR |= GPIO_IDR_IDR_13
//ERROR: Try to read from write-only register
uint32_t val = GPIO->BSRR & GPIO_BSRR_BS_10
```

Basically, such type of errors do not happen often but if it was occurred - it is nightmare to find the root case.

The library propose the no-cost compile-time checks for this.

Worth noting that there are some attempts to resolve this problem
also with modern C++. However, resolving the safety problem,
solutions produced new problems such as hard-to-read, hard-to-use,
inflexibility, loosing some basic opportunities against CMSIS, et cetera.

Summarizing, cpp_register library gets advantages from both traditional and modern approaches without negative effects. Apart from that, author allowed himself to add some general improvements.

### **Features**

The only one requirement - at least C++17 standard (fully supported by the most of compilers).

The library basically contain the only one file - registers.hpp. It is contains three interface classes:

1. **ConstVal** - helper class to transform register value to constexpr value as a type property. This class allows to resolve the problem (constexpr function parameters are not constexpr).
Supported a bit '|' (or) operation.
2. **Field** - type for registers' fields.
3. **Register** - type for registers.

Access mode for the fields and registers - defined in the **AccessMode** enumeration.

**is_register_v** - is inline template constexpr variable to check the value is one of (const) uint8_t, uint16_t, uint32_t.

Some supported operations (stm32f407 as example):

- Set bit(s) '|=' in the register:

```cpp
RCC->AHB1ENR |= RCC_AHB1ENR::GPIODEN;
```

- Reset bit(s) '&=' in the register:

```cpp
RCC->AHB1ENR &= RCC_AHB1ENR::GPIODEN;
```

**Note:** The traditional '&=\~' was replaced by '&=' on purpose but it is possible to use '&=~' instead. (Basically, '\~' has no effect for fields).

- Assign bit(s) '=' in the register:

```cpp
RCC->AHB1ENR = RCC_AHB1ENR::GPIODEN;
```

- Toggle bit(s) '^=' in the register:

```cpp
RCC->AHB1ENR ^= RCC_AHB1ENR::GPIODEN;
```

- Read bit(s) binary '&' of the register:

```cpp
if(RCC->AHB1ENR & RCC_AHB1ENR::GPIODEN)
```

- Read register value '*':

```cpp
const auto value = *(RCC->AHB1ENR);
```

- Assign dynamic value (register value or pointer):

```cpp
uint32_t magic = 0x11223344UL;
RCC->AHB1ENR = magic;
RCC->AHB1ENR = &magic;
```

- Get address unary '&' of the register:

```cpp
uint32_t address = &(RCC->AHB1ENR);
```

- Operate value (from the driver or app level, for example):

```cpp
static constexpr auto SYSTEM_MHZ = 16UL;
static constexpr auto SYST_PERIOD = ConstVal<(SYSTEM_MHZ * 1000000UL) - 1>{};
SYST->RVR = SYST_RVR::RELOAD(SYST_PERIOD);
```

- Operate several fields ad once:

```cpp
SYST->CSR |= (SYST_CSR::CLKSOURCE | SYST_CSR::ENABLE);
```

- Operations with several same fields. It is two forms for the user choice.

```cpp
//Full form
//Set GPIOD pin 12, 13, 14, 15 as output
GPIOD->MODER |= (GPIO_MODER::MODER[NUM_12](NUM_0) | GPIO_MODER::MODER[NUM_13](NUM_0) 
                | GPIO_MODER::MODER[NUM_14](NUM_0) | GPIO_MODER::MODER[NUM_15](NUM_0));
```

```cpp
//Short form
//Set GPIOD pin 12, 13, 14, 15 as output
GPIOD->MODER |= GPIO_MODER::MODER[NUM_12 | NUM_13 | NUM_14 | NUM_15](NUM_0);
```

- The same registers in the array:

```cpp
GPIOA->AFR[NUM] |= GPIO_AFR::AFR[NUM_2](NUM_1 | NUM_0);
```

- Create ConstVal variable:

```cpp
static constexpr auto SYST_CLOCK = to_const_val(168000000UL);
```

**Automated bit-band**:

Useful feature to slightly improve performance for Cortex-M3/M4.
To enable this it is needed to define CORTEX_M_BIT_BAND for the project (-DCORTEX_M_BIT_BAND). In this case, for the set and reset operation the bit-band will be applied automatically if the expression is appropriate for the condition:

- The register address in the bit-band region.
- Only one bit of the register is needed to be set or reset.

### **How to use?**

The reference to use this library was located to the example folder.
It is minimal comprehensive project with LED blinking for stm32f407.
It was written with VSCode + Clang + Make. Also it is builded with
'-Oz' optimization and strict environment '-Werror -Wall -Wextra -Wpedantic -Weverything -pedantic-errors'.

Apart from that, the same gcc example is also located there.

First of all, you have to create the register description header files (as at CMSIS) where you should describe the registers and fields you needed (include register.hpp there). The parameters you should pass to Field and Registers are clear and can be found in the Reference manual for the specific chip.

Apart from that, the python script can be used to transform the *.svd file from the chip maker to register description.
(For example, you can see svd2rust.py for the Rust language).

In tools folder you can find example of the script file with example
of svd file for stm32f407.

To use this script you should pass *.svd file and peripheral modules
you want to generate. (I case only file was passed - all file's modules will be showed you)

In the example/stm32f407 folder you can see the result for:
>py .\svd2cpp.py STM32F407.svd GPIO STK RCC

**It is supposed to use the script to receive only the draft of
the description because \*.svd files contain a ton inaccuracies
and a bit of errors. Apart from that, I am too lazy to write
really comprehensive script for all cases.**

After the register description file finished, it can be included to the project source files and used to write drivers.
