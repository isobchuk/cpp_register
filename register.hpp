/**
 * @file register.hpp
 * @author Ivan Sobchuk (i.a.sobchuk.1994@gmail.com)
 * @brief Metaprogrammed header to work with MCU registers without
 *        any influence to run-time that as written with templates,
 *        constexpr objects, static_assert, overloading and a bit SFINAE.
 *
 * @version 0.1
 * @date 2023-03-09
 *
 * @copyright Ivan Sobchuk (c) 2023
 *
 * License Apache 2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

#pragma once

#include <cstdint>
#include <type_traits>

static_assert((__cplusplus >= 201703L), "Supported only with C++17 and newer!");

// Basic namespace to work with HW
namespace peripheral {

// Add std namespace for all module
using namespace std;

// Register address size is 32 bits all Cortex-M and the most of ARM
using RegisterAddress = uint32_t;

/**
 * @brief Compile-time check if the type if one of the register value type (const) uint8_t, uint16_t, uint32_t
 *
 * @tparam RegisterValue is type to be checked
 */
template <typename RegisterValue>
inline constexpr auto is_register_v = ((is_same_v<remove_cv_t<RegisterValue>, uint8_t>) ||
                                       (is_same_v<remove_cv_t<RegisterValue>, uint16_t>) ||
                                       (is_same_v<remove_cv_t<RegisterValue>, uint32_t>));

/**
 * @brief Struct to make const value (as a type property) from integer
 *
 * @tparam value desired const value
 * @tparam offset desired const offset (additional)
 */
template <const uint32_t value, const uint8_t offset = 0> struct ConstVal final {
  static constexpr uint32_t sc_Value = value << offset;
  static constexpr uint8_t sc_Offset = offset;

  /**
   * @brief Operator '|' to make 'or'  with ConstVal objects
   *
   * @tparam Value const value that should be 'or'
   * @return ConstVal<sc_Value | Value::sc_Value> produced type with new result value (the offset loose the sense)
   */
  template <typename Value> constexpr auto operator|(const Value) const -> ConstVal<sc_Value | Value::sc_Value> {
    static_assert(!(sc_Value & Value::sc_Value), "ConstVal [ operator | ] Some bits of the operands are the same!");
    return {};
  }
};

// Const values for all bits of uin32_t type
inline constexpr ConstVal<1UL, 0> NUM_0{};
inline constexpr ConstVal<1UL, 1> NUM_1{};
inline constexpr ConstVal<1UL, 2> NUM_2{};
inline constexpr ConstVal<1UL, 3> NUM_3{};
inline constexpr ConstVal<1UL, 4> NUM_4{};
inline constexpr ConstVal<1UL, 5> NUM_5{};
inline constexpr ConstVal<1UL, 6> NUM_6{};
inline constexpr ConstVal<1UL, 7> NUM_7{};
inline constexpr ConstVal<1UL, 8> NUM_8{};
inline constexpr ConstVal<1UL, 9> NUM_9{};
inline constexpr ConstVal<1UL, 10> NUM_10{};
inline constexpr ConstVal<1UL, 11> NUM_11{};
inline constexpr ConstVal<1UL, 12> NUM_12{};
inline constexpr ConstVal<1UL, 13> NUM_13{};
inline constexpr ConstVal<1UL, 14> NUM_14{};
inline constexpr ConstVal<1UL, 15> NUM_15{};
inline constexpr ConstVal<1UL, 16> NUM_16{};
inline constexpr ConstVal<1UL, 17> NUM_17{};
inline constexpr ConstVal<1UL, 18> NUM_18{};
inline constexpr ConstVal<1UL, 19> NUM_19{};
inline constexpr ConstVal<1UL, 20> NUM_20{};
inline constexpr ConstVal<1UL, 21> NUM_21{};
inline constexpr ConstVal<1UL, 22> NUM_22{};
inline constexpr ConstVal<1UL, 23> NUM_23{};
inline constexpr ConstVal<1UL, 24> NUM_24{};
inline constexpr ConstVal<1UL, 25> NUM_25{};
inline constexpr ConstVal<1UL, 26> NUM_26{};
inline constexpr ConstVal<1UL, 27> NUM_27{};
inline constexpr ConstVal<1UL, 28> NUM_28{};
inline constexpr ConstVal<1UL, 29> NUM_29{};
inline constexpr ConstVal<1UL, 30> NUM_30{};
inline constexpr ConstVal<1UL, 31> NUM_31{};

// Additional bit band module for the Cortex-m3/m4
namespace bit_band {

// Flag to include automatic bit-band operations
#ifdef CORTEX_M_BIT_BAND
inline constexpr auto BIT_BAND_MODE = true;
#else
inline constexpr auto BIT_BAND_MODE = false;
#endif

/**
 * @brief Memory map for memory regions
 *
 * @tparam origin start address of the region
 * @tparam length length of the region
 */
template <const RegisterAddress origin, const RegisterAddress length> struct Map {
  static constexpr auto sc_Origin = origin;
  static constexpr auto sc_Length = (length * 1024 * 1024);
};

// Regions for the bit-band according to documentation
using Region = Map<0x40000000UL, 1UL>;
using Alias = Map<0x42000000UL, 32UL>;

/**
 * @brief Recalculation address to bit-band address if appropriate
 *
 * @tparam Value the type of value that should be written to address
 * @param address  [in] source address
 * @param value  [in] source value
 * @return constexpr RegisterAddress recalculated bit-band address (if the recalculation is not possible - source
 * address)
 */
template <typename Value> constexpr RegisterAddress bit_band_address(RegisterAddress address, const Value value) {
  static_assert(is_register_v<Value>, "Bit-band The value should be the register!");

  RegisterAddress m_Address = address;
  Value m_Value = value;

  // Check for only one bit is set or Value is not zero
  if ((m_Value & (m_Value - 1)) || (0 == m_Value)) {
    return m_Address;
  }

  // Check the register is fitted to the bit-band area
  if ((m_Address >= Region::sc_Origin) && (m_Address < (Region::sc_Origin + Region::sc_Length))) {
    // Recalculate value according to the bit-band formula
    uint8_t bitNum = 0;
    for (; !(m_Value & (static_cast<decltype(m_Value)>(1) << bitNum)); bitNum++) {
      // Error to avoid infinite loop in case the value is not correct
      if (bitNum >= (sizeof(m_Value) * 8))
        return m_Address;
    }
    m_Address = Alias::sc_Origin + 32 * (m_Address - Region::sc_Origin) + 4 * bitNum;
  }

  return m_Address;
}
} // namespace bit_band

// Access mode for fields
struct AccessMode {
  // All operation that can be done with fields registers
  enum AvailableOperation : uint8_t {
    NONE = 0,

    SET = (1 << 0),    // Equivalent to '|='
    RESET = (1 << 1),  // Equivalent to '&=~'
    ASSIGN = (1 << 2), // Equivalent to '='
    TOGGLE = (1 << 3), // Equivalent to '^='
    READ = (1 << 4),   // Equivalent to '&' or '*'

    MASK = 0xFF
  };

  // All options of access modes for fields
  static constexpr auto RW = (SET | RESET | ASSIGN | TOGGLE | READ);   // read/write
  static constexpr auto R = (READ);                                    // read-only
  static constexpr auto W = (SET | RESET | ASSIGN | TOGGLE);           // write-only
  static constexpr auto RC_W0 = (RESET | READ);                        // read/clear (by '0')
  static constexpr auto RC_W1 = (SET | READ);                          // read/clear (by '1')
  static constexpr auto RC_R = (READ);                                 // read/clear (by read)
  static constexpr auto RC_W = (SET | RESET | ASSIGN | TOGGLE | READ); // read/clear (by write)
  static constexpr auto RS = (SET | READ);                             // read/set
  static constexpr auto RS_R = (READ);                                 // read/set by read
  static constexpr auto RWO = (SET | RESET | ASSIGN | TOGGLE | READ);  // read/write once
  static constexpr auto WO = (SET | RESET | ASSIGN | TOGGLE);          // write once
  static constexpr auto RT_W = (SET | RESET | ASSIGN | TOGGLE | READ); // read-only/trigger
  static constexpr auto RT_W1 = (SET | READ);                          // read-only/write trigger
  static constexpr auto T = (TOGGLE);                                  // toggle
  static constexpr auto RES = (NONE);                                  // reserved
};

// Empty type to sign all field types
class FieldMark {};

/**
 * @brief Field class with data and operations for the register fields
 *
 * @tparam T the register type of the field
 * @tparam value the value of the field
 * @tparam access the access mode of the field
 * @tparam fieldSize the size of the field
 * @tparam fieldNumber the number of the same fields in the register
 */
template <typename T, const typename T::Size value, const uint8_t access, const uint8_t fieldSize,
          const uint8_t fieldNumber = 1>
class Field final : FieldMark {
  // Check for input arguments
  static_assert((is_register_v<decltype(value)>), "Peripheral field  The value should be the register type!");
  static_assert((value), "Peripheral field  The value should be not zero!");
  static_assert(
      ((fieldSize * fieldNumber) && ((fieldSize * fieldNumber) <= (sizeof(decltype(value)) * 8))),
      "Peripheral field  The field size and number should be more than 0 and less than sizeof(Register::Size)!");

  // Flag of the short form for multi-filed operations
  static constexpr uint8_t sc_ShortFormFlag = 0x80;

  static constexpr auto sc_Size = fieldSize;     // Size of the field (for multiple fields)
  static constexpr auto sc_Number = fieldNumber; // The same field number in the registers
  static constexpr auto sc_Offset = []() {       // The offset of the field from the register address
    remove_const_t<decltype(value)> offset = 0;
    for (unsigned int i = 0; (i < sizeof(value) * 8); i++) {
      if ((static_cast<decltype(value)>(1UL) << i) & value) {
        offset = i;
        break;
      }
    }
    return offset;
  }();

  // Inner function to create mask by value
  static constexpr auto scl_FieldMask = [](decltype(value) val) {
    remove_const_t<decltype(val)> mask = 0;

    for (uint8_t i = 0; i < (sizeof(decltype(val)) * 8); i++) {
      if ((val & (static_cast<decltype(val)>(1UL) << i))) {
        for (uint8_t j = 0; j < sc_Size; j++) {
          mask |= (static_cast<decltype(val)>(1UL) << (j + (i * sc_Size)));
        }
      }
    }
    return mask;
  };

  // Inner checking for the compound short form
  static constexpr auto scl_isCompound = [](decltype(value) val) { return (val & (val - 1)) ? sc_ShortFormFlag : 0; };

  // Inner form field
  static constexpr auto scl_FormField = [](decltype(value) valueSource, decltype(value) valueTarget,
                                           decltype(sc_Offset) offset) {
    return (scl_isCompound(valueTarget)) ? scl_FieldMask(valueTarget) : valueSource << offset;
  };

  // Inner write field
  static constexpr auto scl_WriteField = [](decltype(value) val) {
    remove_const_t<decltype(val)> mask = 0;

    if (sc_ShortFormFlag & access) {
      for (uint8_t i = 0; i < (sizeof(decltype(val)) * 8); i += sc_Size) {
        if ((value & (static_cast<decltype(val)>(1UL) << i))) {
          mask |= (value & (val << i));
        }
      }
    } else {
      mask = val << sc_Offset;
    }

    return mask;
  };

public:
  using Register = T;                       // Type of the register which contains the field
  static constexpr auto sc_Value = value;   // The field value
  static constexpr auto sc_Access = access; // The field access mode

  /**
   * @brief Operator '|' to make 'or'  with field objects
   *
   * @tparam Value the value that should be 'or' with the source value
   * @return Field<Register, (sc_Value | Value::sc_Value), (sc_Access & Value::sc_Access), sc_Size, sc_Number> the new
   * produced type
   */
  template <typename Value>
  constexpr auto operator|(const Value) const noexcept
      -> Field<Register, (sc_Value | Value::sc_Value), (sc_Access & Value::sc_Access), sc_Size, sc_Number> {
    static_assert(!(sc_Value & Value::sc_Value),
                  "Peripheral field [ operator | ] Some bits of the operands are the same!");
    static_assert((is_same_v<typename Value::Register, Register>),
                  "Peripheral field [ operator | ] The fields are from different register!");
    return {};
  }

  /**
   * @brief Operator '~' for '&=' operation (reset bit). Only for the compatibility.
   *
   * @return Field<Register, sc_Value, sc_Access, sc_Size, sc_Number>  the new produced type
   */
  constexpr auto operator~() const noexcept -> Field<Register, sc_Value, sc_Access, sc_Size, sc_Number> { return {}; }

  /**
   * @brief Operator '[]' to create the same fields in the register
   *
   * @tparam FieldNumber The field number of the same fields in the register
   * @return Field<Register, scl_FormField(sc_Value, FieldNumber::sc_Value, FieldNumber::sc_Offset *sc_Size),
   * (scl_isCompound(FieldNumber::sc_Value) | sc_Access), sc_Size, sc_Number> The new produced type
   */
  template <typename FieldNumber>
  constexpr auto operator[](const FieldNumber) const noexcept
      -> Field<Register, scl_FormField(sc_Value, FieldNumber::sc_Value, FieldNumber::sc_Offset *sc_Size),
               (scl_isCompound(FieldNumber::sc_Value) | sc_Access), sc_Size, sc_Number> {
    static_assert((sc_Number > 1), "Peripheral field [ operator [] ] No fields with the same name in the register!");
    static_assert((FieldNumber::sc_Offset <= sc_Number),
                  "Peripheral field [ operator [] ] The field number was overflowed!");
    return {};
  }

  /**
   * @brief Operator '()' to create multi-bit fields
   *
   * @tparam BitNumber The value should be written in the current field.
   * @return Field<Register, scl_WriteField(BitNumber::sc_Value), sc_Access, sc_Size, sc_Number> The new produced typ
   */
  template <typename BitNumber>
  constexpr auto operator()(const BitNumber) const noexcept
      -> Field<Register, scl_WriteField(BitNumber::sc_Value), sc_Access, sc_Size, sc_Number> {

    // Check size of the value
    constexpr auto cl_MaxValue = []() {
      remove_const_t<decltype(sc_Value)> maxValue = 0;
      for (unsigned int i = 0; i < sc_Size; i++) {
        maxValue |= (static_cast<decltype(maxValue)>(1UL) << i);
      }
      return maxValue;
    }();

    static_assert((BitNumber::sc_Value <= cl_MaxValue),
                  "Peripheral field [ operator [] ] The bit number was overflowed!");
    return {};
  }
};

/**
 * @brief Register class with data and operations with it
 *
 * @tparam address The address of the register
 * @tparam access The access mode for the register
 * @tparam SizeT The size type of the register
 */
template <const RegisterAddress address, const uint8_t access, typename SizeT = uint32_t> class Register final {
  static constexpr auto sc_Address = address; // The register address
  static constexpr auto sc_Access = access;   // The register access mode

  // Inner function to get bit-band address
  template <typename Value> static constexpr auto get_bit_band_address(const Value) {
    if constexpr (bit_band::BIT_BAND_MODE) {
      constexpr RegisterAddress bitBandAddress = bit_band::bit_band_address(sc_Address, Value::sc_Value);
      return bitBandAddress;
    }
    return sc_Address;
  }

public:
  using Size = SizeT; // Type of the value

  /**
   * @brief 'Set' or '|=' for the register
   *
   * @tparam Value The value (Field type) should be set
   * @return enable_if_t<is_base_of_v<FieldMark, Value>, void>:
   */
  template <typename Value>
  inline enable_if_t<is_base_of_v<FieldMark, Value>, void> operator|=(const Value) const noexcept {
    static_assert((is_same_v<const Register, typename Value::Register>),
                  "Peripheral registers [set] The register does not contain the field!");
    static_assert((Value::sc_Access & sc_Access & AccessMode::SET),
                  "Peripheral registers [set] Invalid operation for the field!");

    constexpr auto bitBandAddress = get_bit_band_address(Value{});
    if constexpr (sc_Address != bitBandAddress) {
      *reinterpret_cast<volatile SizeT *>(bitBandAddress) = 1;
    } else {
      *reinterpret_cast<volatile SizeT *>(sc_Address) |= Value::sc_Value;
    }
  }

  /**
   * @brief 'Reset' or '&=' for the register
   *
   * @tparam Value The value (Field type) should be reset
   * @return enable_if_t<is_base_of_v<FieldMark, Value>, void>:
   */
  template <typename Value>
  inline enable_if_t<is_base_of_v<FieldMark, Value>, void> operator&=(const Value) const noexcept {
    static_assert((is_same_v<const Register, typename Value::Register>),
                  "Peripheral registers [reset] The register does not contain the field!");
    static_assert((Value::sc_Access & sc_Access & AccessMode::RESET),
                  "Peripheral registers [reset] Invalid operation for the field!");

    constexpr auto bitBandAddress = get_bit_band_address(Value{});
    if constexpr (sc_Address != bitBandAddress) {
      *reinterpret_cast<volatile SizeT *>(bitBandAddress) = 0;
    } else {
      *reinterpret_cast<volatile SizeT *>(sc_Address) &= ~Value::sc_Value;
    }
  }

  /**
   * @brief 'Assign' or '=' for the register
   *
   * @tparam Value The value (Field type) should be assigned
   * @return enable_if_t<is_base_of_v<FieldMark, Value>, void>:
   */
  template <typename Value>
  inline enable_if_t<is_base_of_v<FieldMark, Value>, void> operator=(const Value) const noexcept {
    static_assert((is_same_v<const Register, typename Value::Register>),
                  "Peripheral registers [assign] The register does not contain the field!");
    static_assert((Value::sc_Access & sc_Access & AccessMode::ASSIGN),
                  "Peripheral registers [assign] Invalid operation for the field!");

    *reinterpret_cast<volatile SizeT *>(sc_Address) = Value::sc_Value;
  }

  /**
   * @brief 'Toggle' or '^=' for the register
   *
   * @tparam Value The value (Field type) should be toggled
   * @return enable_if_t<is_base_of_v<FieldMark, Value>, void>:
   */
  template <typename Value>
  inline enable_if_t<is_base_of_v<FieldMark, Value>, void> operator^=(const Value) const noexcept {
    static_assert((is_same_v<const Register, typename Value::Register>),
                  "Peripheral registers [toggle] The register does not contain the field!");
    static_assert((Value::sc_Access & sc_Access & AccessMode::TOGGLE),
                  "Peripheral registers [toggle] Invalid operation for the field!");

    *reinterpret_cast<volatile SizeT *>(sc_Address) ^= Value::sc_Value;
  }

  /**
   * @brief 'Read bit' or '&' for the register
   *
   * @tparam Value The value (Field type) should be read
   * @return enable_if_t<is_base_of_v<FieldMark, Value>, bool>:
   */
  template <typename Value>
  inline enable_if_t<is_base_of_v<FieldMark, Value>, bool> operator&(const Value) const noexcept {
    static_assert((is_same_v<const Register, typename Value::Register>),
                  "Peripheral registers [read bit] The register does not contain the field!");
    static_assert((Value::sc_Access & sc_Access & AccessMode::READ),
                  "Peripheral registers [read bit] Invalid operation for the field!");

    return static_cast<bool>(*reinterpret_cast<volatile SizeT *>(sc_Address) & Value::sc_Value);
  }

  /**
   * @brief 'Read' or '*' for the register
   *
   * @return SizeT The value is currently stored in the register
   */
  inline SizeT operator*() const noexcept {
    static_assert((sc_Access & AccessMode::READ), "Peripheral registers [read] Invalid operation for the register!");

    return *reinterpret_cast<volatile SizeT *>(sc_Address);
  }

  /**
   * @brief Dynamic 'Assign' or '=' for the register
   *
   * @tparam Value register_t or pointer
   * @param value  [in] The value (dynamic) should be assigned
   * @return enable_if_t<(is_register_v<Value> || is_pointer_v<Value>), void>:
   */
  template <typename Value>
  inline enable_if_t<(is_register_v<Value> || is_pointer_v<Value>), void> operator=(const Value value) const noexcept {
    static_assert((sc_Access & AccessMode::ASSIGN), "Peripheral registers [assign] Invalid operation for the field!");

    if constexpr (is_pointer_v<Value>) {
      *reinterpret_cast<volatile SizeT *>(sc_Address) = reinterpret_cast<SizeT>(value);
    } else {
      *reinterpret_cast<volatile SizeT *>(sc_Address) = value;
    }
  }

  /**
   * @brief 'Get Address' or '&' for the register
   *
   * @return constexpr SizeT The const address of the register
   */
  inline constexpr SizeT operator&() { return sc_Address; }
};

} // namespace peripheral
