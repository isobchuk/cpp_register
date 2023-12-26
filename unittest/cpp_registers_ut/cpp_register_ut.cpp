#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "register.hpp"

using namespace cpp_register;
using namespace cpp_register::constants;

TEST_SUITE_BEGIN("Check RegVal");
TEST_CASE("Unsigned value") {
  CHECK_EQ(0U, reg_v<0U>.sc_Value);
  CHECK_EQ(114U, reg_v<114U>.sc_Value);
  CHECK_EQ(56732U, reg_v<56732U>.sc_Value);
  CHECK_EQ(0x123456UL, reg_v<0x123456UL>.sc_Value);
  CHECK_EQ(UINT32_MAX, reg_v<UINT32_MAX>.sc_Value);
  CHECK_EQ(UINT64_MAX, reg_v<UINT64_MAX>.sc_Value);
  CHECK_EQ(0U, reg_v<56732U>.sc_Offset);
  CHECK_EQ(0U, reg_v<UINT32_MAX>.sc_Offset);
  CHECK_EQ(0x0100U, reg_v<1UL, 8>.sc_Value);
  CHECK_EQ(11U, reg_v<11U, 0>.sc_Value);
  CHECK_EQ(0x100000000UL, reg_v<1ULL, 32>.sc_Value);
}

TEST_CASE("Pointer value") {
  static uint8_t buffer[8];
  CHECK_EQ(buffer, reg_v<buffer>.sc_Value);
}

TEST_CASE("Enum class value") {
  enum class TestEnum : uint32_t { JustAValue = 2345UL };
  CHECK_EQ(static_cast<uint32_t>(TestEnum::JustAValue), reg_v<TestEnum::JustAValue>.sc_Value);
}

TEST_CASE("Check bitwise OR") {
  enum class TestEnum1 : uint32_t { JustAValue = 0x2345UL };
  enum class TestEnum2 : uint32_t { JustAValue = 0xABCD'8000UL };
  constexpr auto testValue = reg_v<TestEnum1::JustAValue> | reg_v<TestEnum2::JustAValue>;
  CHECK_EQ((static_cast<uint32_t>(TestEnum1::JustAValue) | static_cast<uint32_t>(TestEnum2::JustAValue)), testValue.sc_Value);
}
TEST_SUITE_END();

TEST_SUITE_BEGIN("Check Hardware registers");

template <const cpp_register::RegisterAddress address> struct TEST_REGISTERS_T {
  static constexpr cpp_register::Register<address + 0x0, cpp_register::AccessMode::RW, void *, struct TEST1> TEST1{};
  static constexpr cpp_register::Register<address + 0x8, cpp_register::AccessMode::RW, uint32_t, struct TEST2> TEST2{};
  static constexpr cpp_register::Register<address + 0xC, cpp_register::AccessMode::RW, uint32_t, struct TEST3> TEST3{};
  static constexpr cpp_register::Register<address + 0x10, cpp_register::AccessMode::RW, uint32_t, struct TEST4> TEST4{};
  static constexpr cpp_register::Register<address + 0x14, cpp_register::AccessMode::RW, uint32_t, struct TEST5> TEST5{};
  static constexpr cpp_register::Register<address + 0x18, cpp_register::AccessMode::RW, uint32_t, struct TEST6> TEST6{};
  static constexpr cpp_register::Register<address + 0x1C, cpp_register::AccessMode::RW, uint32_t, struct TEST7> TEST7{};
  static constexpr cpp_register::Register<address + 0x20, cpp_register::AccessMode::RW, uint32_t, struct TEST8> TEST8{};
};

inline constexpr TEST_REGISTERS_T<0x40000000> const *REG_TEST{};

struct TEST1_POINTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST1), nullptr, cpp_register::AccessMode::RW, 64> VAL1{};
};

struct TEST2_REGISTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST2), (1UL << 0), cpp_register::AccessMode::RW, 2> VAL1{};
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST2), (1UL << 2), cpp_register::AccessMode::RW, 1> VAL2{};
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST2), (1UL << 4), cpp_register::AccessMode::RW, 2> VAL3{};
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST2), (1UL << 16), cpp_register::AccessMode::RW, 1> VAL4{};
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST2), (1UL << 28), cpp_register::AccessMode::RW, 4> VAL5{};
};

struct TEST3_REGISTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST3), (1UL << 0), cpp_register::AccessMode::RW, 4, 8> VAL1{};
};

struct TEST4_REGISTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST4), (1UL << 8), cpp_register::AccessMode::RW, 4, 6> VAL1{};
};

struct TEST5_REGISTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST5), (1UL << 0), cpp_register::AccessMode::RW, 4> VAL1{};
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST5), (1UL << 4), cpp_register::AccessMode::RW, 2, 8> VAL2{};
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST5), (1UL << 20), cpp_register::AccessMode::RW, 1> VAL3{};
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST5), (1UL << 24), cpp_register::AccessMode::RW, 8> VAL4{};
};

struct TEST6_REGISTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST6), (1UL << 8), cpp_register::AccessMode::RW, 4, 3, 4> VAL1{};
};

struct TEST7_REGISTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST7), (1UL << 6), cpp_register::AccessMode::RW, 2, 4, 6> VAL1{};
};

struct TEST8_REGISTER {
  static constexpr cpp_register::Field<decltype(REG_TEST->TEST8), (1UL << 0), cpp_register::AccessMode::RW, 1, 32> VAL1{};
};

TEST_CASE("Check compile-time pointer value") {
  static uint8_t buffer[8];
  CHECK_EQ(TEST1_POINTER::VAL1(reg_v<buffer>).sc_Value, buffer);
}

TEST_CASE("Check compile-time register value") {
  enum class TestValues : uint32_t { TestValue = 7U };

  constexpr auto CHECK_VALUE = (TEST2_REGISTER::VAL1(NUM_0 | NUM_1) | TEST2_REGISTER::VAL2 | TEST2_REGISTER::VAL3(NUM_1) |
                                TEST2_REGISTER::VAL4(NUM_0) | TEST2_REGISTER::VAL5(reg_v<TestValues::TestValue>));

  CHECK_EQ(CHECK_VALUE.sc_Value, 0x7001'0027UL);
}

TEST_CASE("Check compile-time multi-bit register value") {
  enum class TestValues : uint32_t { TestValue = 5U };

  constexpr auto CHECK_VALUE1 = TEST3_REGISTER::VAL1[NUM_2](reg_v<TestValues::TestValue>) |
                                TEST3_REGISTER::VAL1[NUM_3](reg_v<TestValues::TestValue>) |
                                TEST3_REGISTER::VAL1[NUM_5](reg_v<TestValues::TestValue>) | TEST3_REGISTER::VAL1[NUM_7](reg_v<TestValues::TestValue>);

  constexpr auto CHECK_VALUE2 = TEST3_REGISTER::VAL1[NUM_2 | NUM_3 | NUM_5 | NUM_7](reg_v<TestValues::TestValue>);

  CHECK_EQ(CHECK_VALUE1.sc_Value, CHECK_VALUE2.sc_Value);
  CHECK_EQ(CHECK_VALUE1.sc_Value, 0x5050'5500UL);
  CHECK_EQ(CHECK_VALUE2.sc_Value, 0x5050'5500UL);
}

TEST_CASE("Check compile-time multi-bit register value with offset") {
  enum class TestValues : uint32_t { TestValue = 6U };
  constexpr auto CHECK_VALUE1 = TEST4_REGISTER::VAL1[NUM_0](reg_v<TestValues::TestValue>) |
                                TEST4_REGISTER::VAL1[NUM_1](reg_v<TestValues::TestValue>) |
                                TEST4_REGISTER::VAL1[NUM_3](reg_v<TestValues::TestValue>) | TEST4_REGISTER::VAL1[NUM_5](reg_v<TestValues::TestValue>);

  constexpr auto CHECK_VALUE2 = TEST4_REGISTER::VAL1[NUM_0 | NUM_1 | NUM_3 | NUM_5](reg_v<TestValues::TestValue>);

  CHECK_EQ(CHECK_VALUE1.sc_Value, CHECK_VALUE2.sc_Value);
  CHECK_EQ(CHECK_VALUE1.sc_Value, 0x6060'6600UL);
  CHECK_EQ(CHECK_VALUE2.sc_Value, 0x6060'6600UL);
}

TEST_CASE("Check compile-time complex register") {
  constexpr auto CHECK_VALUE = TEST5_REGISTER::VAL1(reg_v<2U>) |
                               TEST5_REGISTER::VAL2[reg_v<1UL, 2> | reg_v<1UL, 3> | reg_v<1UL, 4> | reg_v<1UL, 5>](reg_v<2U>) | TEST5_REGISTER::VAL3 |
                               TEST5_REGISTER::VAL4(reg_v<0xDAU>);

  CHECK_EQ(CHECK_VALUE.sc_Value, 0xDA10'AA02UL);
}

TEST_CASE("Check compile-time multi-bit register value with offset and span") {
  enum class TestValues : uint32_t { TestValue = 3U };
  constexpr auto CHECK_VALUE1 = TEST6_REGISTER::VAL1[NUM_0](reg_v<TestValues::TestValue>) | TEST6_REGISTER::VAL1[NUM_2](reg_v<TestValues::TestValue>);

  constexpr auto CHECK_VALUE2 = TEST6_REGISTER::VAL1[NUM_0 | NUM_2](reg_v<TestValues::TestValue>);

  CHECK_EQ(CHECK_VALUE1.sc_Value, CHECK_VALUE2.sc_Value);
  CHECK_EQ(CHECK_VALUE1.sc_Value, 0x0300'0300UL);
  CHECK_EQ(CHECK_VALUE2.sc_Value, 0x0300'0300UL);
}

TEST_CASE("Check compile-time multi-bit register value with offset and span 2") {
  enum class TestValues : uint32_t { TestValue = 2U };
  constexpr auto CHECK_VALUE1 = TEST7_REGISTER::VAL1[NUM_0](reg_v<TestValues::TestValue>) |
                                TEST7_REGISTER::VAL1[NUM_1](reg_v<TestValues::TestValue>) |
                                TEST7_REGISTER::VAL1[NUM_2](reg_v<TestValues::TestValue>) | TEST7_REGISTER::VAL1[NUM_3](reg_v<TestValues::TestValue>);

  constexpr auto CHECK_VALUE2 = TEST7_REGISTER::VAL1[NUM_0 | NUM_1 | NUM_2 | NUM_3](reg_v<TestValues::TestValue>);

  CHECK_EQ(CHECK_VALUE1.sc_Value, CHECK_VALUE2.sc_Value);
  CHECK_EQ(CHECK_VALUE1.sc_Value, 0x8080'8080UL);
  CHECK_EQ(CHECK_VALUE2.sc_Value, 0x8080'8080UL);
}

TEST_CASE("Check compile-time single-bit register value") {
  enum class TestValues : uint32_t { TestValue = 1U };
  constexpr auto CHECK_VALUE1 =
      TEST8_REGISTER::VAL1[NUM_5] | TEST8_REGISTER::VAL1[NUM_16] | TEST8_REGISTER::VAL1[NUM_24] | TEST8_REGISTER::VAL1[NUM_28];

  constexpr auto CHECK_VALUE2 = TEST8_REGISTER::VAL1[NUM_5 | NUM_16 | NUM_24 | NUM_28];

  CHECK_EQ(CHECK_VALUE1.sc_Value, CHECK_VALUE2.sc_Value);
  CHECK_EQ(CHECK_VALUE1.sc_Value, 0x1101'0020UL);
  CHECK_EQ(CHECK_VALUE2.sc_Value, 0x1101'0020UL);
}

TEST_SUITE_END();