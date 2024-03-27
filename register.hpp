/**
 * @file register.hpp
 * @author Ivan Sobchuk (i.a.sobchuk.1994@gmail.com)
 * @brief Metaprogrammed header to work with MCU registers without
 *        any influence to run-time that as written with templates,
 *        constexpr objects, static_assert, overloading and a bit SFINAE.
 *
 * @version 1.0.1
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

// C++ concepts should be enabled
static_assert((__cplusplus >= 202002L), "Supported only with C++20 and newer!");

// Basic namespace to work with HW
namespace cpp_register {

// Register address size is 32 bits all Cortex-M and the most of ARM
using RegisterAddress = uint32_t;

namespace val_valid {
/**
 * @brief Compile-time check if the type if one of the register value type: unsigned arithmetic, pointer (to static) or enum (class) with base
 * unsigned arithmetic
 *
 * @tparam Value Type to check
 */
template <typename Value>
concept register_value =
    std::is_unsigned_v<Value> || std::is_pointer_v<Value> || (std::is_enum_v<Value> && std::is_unsigned_v<std::underlying_type_t<Value>>);

/**
 * @brief Check that offset does not exceed max type size
 *
 * @tparam Value  Type of value
 * @tparam offset Desired offset
 */
template <typename Value, const uint8_t offset>
concept register_offset = ("The offset should be fitted to the type size!", (offset < (sizeof(Value) * 8)));

/**
 * @brief Check the pointer to be initialized and without offset (also no pointer - true)
 *
 * @tparam pPointer Address of the buffer value, should be not nullptr
 * @tparam pOffset  Offset, should be zero
 */
template <const auto pPointer, const uint8_t pOffset> struct is_pointer_valid final {
  static constexpr auto value = true;
};

/**
 * @brief Specialization for pointers to check the conditions listed in the general template
 *
 * @tparam *pPointer Address of the buffer value, should be not nullptr
 * @tparam pOffset   Offset, should be zero
 */
template <auto *pPointer, uint8_t pOffset> struct is_pointer_valid<pPointer, pOffset> final {
  static constexpr auto value = (0 == pOffset) && (nullptr != pPointer) ? true : false;
};

// Variable alias
template <const auto pPointer, const uint8_t pOffset = 0> inline constexpr auto is_pointer_valid_v = is_pointer_valid<pPointer, pOffset>::value;

/**
 * @brief Check that pointer is initialized (in case of no-pointer - returns true)
 *
 * @tparam tpValue  Pointer value
 * @tparam tpOffset Value offset
 */
template <const auto tpValue, const uint8_t tpOffset>
concept register_pointer = ("In case of pointer value - should not be nullptr and without offset!", is_pointer_valid_v<tpValue, tpOffset>);

/**
 * @brief Compile-time check for being RegVal class (with public interface)
 *
 * @tparam T Type to check
 */
template <typename T>
concept reg_val = requires(T) {
  typename T::RegValT;
  T::sc_Offset;
  T::sc_Value;
  T::sc_IsPointer;
};

/**
 * @brief Class to make const Register value to write to register
 *
 * @tparam tpValue Desired const value, can be one of unsigned arithmetic, pointer (to static) or enum (class) with base unsigned arithmetic
 * @tparam tpOffset Desired const offset (additional, considered only valid only for unsigned and enum values)
 */
template <const auto tpValue, const uint8_t tpOffset = 0>
requires register_value<decltype(tpValue)> && register_offset<decltype(tpValue), tpOffset> && register_pointer<tpValue, tpOffset>
class RegVal final {
  template <typename Value>
  inline static consteval std::enable_if_t<std::is_unsigned_v<Value>, Value> cast_value(const Value val, const uint8_t offset) {
    return val << offset;
  }
  template <typename Value>
  inline static consteval std::enable_if_t<std::is_pointer_v<Value>, Value> cast_value(const Value val, const uint8_t offset) {
    return val;
  }
  template <typename Value>
  inline static consteval std::enable_if_t<std::is_enum_v<Value>, std::underlying_type_t<Value>> cast_value(const Value val, const uint8_t offset) {
    return static_cast<std::underlying_type_t<Value>>(val) << offset;
  }

public:
  static constexpr uint8_t sc_Offset = tpOffset;
  static constexpr auto sc_Value = cast_value(tpValue, sc_Offset);
  static constexpr auto sc_IsPointer = std::is_pointer_v<decltype(tpValue)>;
  struct RegValT;

  /**
   * @brief Operator '|' to make 'or' with RegVal objects
   *
   * @constraints:  1) Value should be RegVal type
   *                2) Value bits of the operands should not be the same
   *                3) Values should not be a pointers
   *
   * @tparam Value Const value that should be 'or'
   * @return RegVal<sc_Value | Value::sc_Value> produced type with new result value (the offset loose the sense)
   */
  template <typename Value>
  requires reg_val<Value> && (!((std::is_pointer_v<decltype(Value::sc_Value)>) || (std::is_pointer_v<decltype(sc_Value)>))) &&
           (!(sc_Value & Value::sc_Value))
  consteval auto operator|(const Value) const -> RegVal<sc_Value | Value::sc_Value> {
    return {};
  }
};
} // namespace val_valid

// Variable alias
template <const auto tpValue, const uint8_t tpOffset = 0U> inline constexpr auto reg_v = val_valid::RegVal<tpValue, tpOffset>{};

namespace constants {
// Const values for all bits of uint32_t type (Usually only for tests)
inline constexpr val_valid::RegVal<0UL> ZERO{};
inline constexpr val_valid::RegVal<1UL, 0> NUM_0{};
inline constexpr val_valid::RegVal<1UL, 1> NUM_1{};
inline constexpr val_valid::RegVal<1UL, 2> NUM_2{};
inline constexpr val_valid::RegVal<1UL, 3> NUM_3{};
inline constexpr val_valid::RegVal<1UL, 4> NUM_4{};
inline constexpr val_valid::RegVal<1UL, 5> NUM_5{};
inline constexpr val_valid::RegVal<1UL, 6> NUM_6{};
inline constexpr val_valid::RegVal<1UL, 7> NUM_7{};
inline constexpr val_valid::RegVal<1UL, 8> NUM_8{};
inline constexpr val_valid::RegVal<1UL, 9> NUM_9{};
inline constexpr val_valid::RegVal<1UL, 10> NUM_10{};
inline constexpr val_valid::RegVal<1UL, 11> NUM_11{};
inline constexpr val_valid::RegVal<1UL, 12> NUM_12{};
inline constexpr val_valid::RegVal<1UL, 13> NUM_13{};
inline constexpr val_valid::RegVal<1UL, 14> NUM_14{};
inline constexpr val_valid::RegVal<1UL, 15> NUM_15{};
inline constexpr val_valid::RegVal<1UL, 16> NUM_16{};
inline constexpr val_valid::RegVal<1UL, 17> NUM_17{};
inline constexpr val_valid::RegVal<1UL, 18> NUM_18{};
inline constexpr val_valid::RegVal<1UL, 19> NUM_19{};
inline constexpr val_valid::RegVal<1UL, 20> NUM_20{};
inline constexpr val_valid::RegVal<1UL, 21> NUM_21{};
inline constexpr val_valid::RegVal<1UL, 22> NUM_22{};
inline constexpr val_valid::RegVal<1UL, 23> NUM_23{};
inline constexpr val_valid::RegVal<1UL, 24> NUM_24{};
inline constexpr val_valid::RegVal<1UL, 25> NUM_25{};
inline constexpr val_valid::RegVal<1UL, 26> NUM_26{};
inline constexpr val_valid::RegVal<1UL, 27> NUM_27{};
inline constexpr val_valid::RegVal<1UL, 28> NUM_28{};
inline constexpr val_valid::RegVal<1UL, 29> NUM_29{};
inline constexpr val_valid::RegVal<1UL, 30> NUM_30{};
inline constexpr val_valid::RegVal<1UL, 31> NUM_31{};
} // namespace constants

// Additional bit band module for the Cortex-m3/m4
namespace bit_band::cortex_m {
/**
 * @brief Memory map for memory regions
 *
 * @tparam tpOrigin Start address of the region
 * @tparam tpLength Length of the region
 */
template <const RegisterAddress tpOrigin, const RegisterAddress tpLength> struct Map {
  static constexpr auto sc_Origin = tpOrigin;
  static constexpr auto sc_Length = (tpLength * 1024 * 1024);
};

// Regions for the bit-band according to documentation
using Region = Map<0x40000000UL, 1UL>;
using Alias = Map<0x42000000UL, 32UL>;

/**
 * @brief Recalculation address to bit-band address if appropriate
 *
 * @tparam Value The type of value that should be written to address
 * @param pAddress  [in] Source address
 * @param pValue  [in] Source value
 * @return constexpr RegisterAddress Recalculated bit-band address (if the recalculation is not possible - source
 * address)
 */
template <typename Value>
requires val_valid::register_value<Value>
consteval RegisterAddress bit_band_address(RegisterAddress pAddress, const Value pValue) {
  RegisterAddress m_Address = pAddress;
  Value m_Value = pValue;

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
} // namespace bit_band::cortex_m

// Flag to include automatic bit-band operations (a bit straightforward but simple)
#if defined BIT_BAND_CORTEX_M && defined BIT_BAND_CUSTOM
#error "The only one bit_band algorithm can be used in the same time!"
#endif

#ifdef BIT_BAND_CORTEX_M
inline constexpr auto BIT_BAND_MODE = true;
template <typename Value>
requires val_valid::register_value<Value>
inline consteval RegisterAddress bit_band_addr(RegisterAddress pAddress, const Value pValue) {
  return bit_band::cortex_m::bit_band_address(pAddress, pValue);
}
#elif BIT_BAND_CUSTOM // For the custom bit_band the recalculation function should be provided
#include "bit_band_custom.hpp"
inline constexpr auto BIT_BAND_MODE = true;
template <typename Value>
requires val_valid::register_value<Value>
inline consteval RegisterAddress bit_band_addr(RegisterAddress pAddress, const Value pValue) {
  return bit_band::custom::bit_band_address(pAddress, pValue);
}
#else
inline constexpr auto BIT_BAND_MODE = false;
#endif

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

/**
 * @brief Compile-time check for being Field class (with public interface)
 *
 * @tparam T Type to check
 */
template <typename T>
concept field = requires(T) {
  typename T::FieldT;
  typename T::Register;
  T::sc_Value;
  T::sc_Access;
};

/**
 * @brief Field class with data and operations for the register fields
 *
 * @tparam T The register type of the field
 * @tparam tpValue The value of the field
 * @tparam tpAccess The access mode of the field
 * @tparam tpFieldSize The size of the field
 * @tparam tpFieldNumber The number of the same fields in the register
 * @tparam tpStep The span between the same fields in the register
 */
template <typename T, const typename T::Size tpValue, const uint8_t tpAccess, const uint8_t tpFieldSize, const uint8_t tpFieldNumber = 1,
          const uint8_t tpStep = 0>
requires val_valid::register_value<decltype(tpValue)>
class Field final {
  static_assert(((0 != (tpFieldSize * tpFieldNumber)) && ((tpFieldSize * tpFieldNumber) <= (sizeof(decltype(tpValue)) * 8))),
                "Peripheral field  The field size and number should be more than 0 and less than sizeof(Register::Size)!");

  // Flag of the short form for multi-filed operations
  static constexpr uint8_t sc_ShortFormFlag = 0x80U;

  static constexpr auto sc_Size = tpFieldSize;     // Size of the field (for multiple fields)
  static constexpr auto sc_Number = tpFieldNumber; // The same field number in the registers
  static constexpr auto sc_Step = tpStep;          // The step between the same fields
  static constexpr auto sc_Offset = []() {         // The offset of the field from the register address
    if constexpr (!std::is_pointer_v<decltype(tpValue)>) {
      std::remove_const_t<decltype(tpValue)> offset = 0;
      for (unsigned int i = 0; (i < sizeof(tpValue) * 8); i++) {
        if ((static_cast<decltype(tpValue)>(1UL) << i) & tpValue) {
          offset = i;
          break;
        }
      }
      return offset;
    } else {
      return 0U;
    }

  }();

  // Inner function to create mask by value
  static constexpr auto scl_FieldMask = [](decltype(tpValue) pValue) {
    if constexpr (!std::is_pointer_v<decltype(tpValue)>) {
      std::remove_const_t<decltype(pValue)> mask = 0;
      for (uint8_t i = 0; i < (sizeof(decltype(pValue)) * 8); i++) {
        if ((pValue & (static_cast<decltype(pValue)>(1UL) << i))) {
          for (uint8_t j = 0; j < sc_Size; j++) {
            mask |= (static_cast<decltype(pValue)>(1UL) << (j + (i * (sc_Size + sc_Step))));
          }
        }
      }
      return mask;
    } else {
      return 0U;
    }
  };

  // Inner checking for the compound short form
  static constexpr auto scl_isCompound = [](decltype(tpValue) pValue) {
    if constexpr (!std::is_pointer_v<decltype(tpValue)>) {
      return (pValue & (pValue - 1)) ? sc_ShortFormFlag : 0;
    } else {
      return 0;
    }
  };

  // Inner form field
  static constexpr auto scl_FormField = [](decltype(tpValue) pValueSource, decltype(tpValue) pValueTarget, decltype(sc_Offset) pOffset) {
    if constexpr (!std::is_pointer_v<decltype(tpValue)>) {
      return (scl_isCompound(pValueTarget)) ? scl_FieldMask(pValueTarget) << sc_Offset : pValueSource << pOffset * (sc_Size + sc_Step);
    } else {
      return 0;
    }
  };

  // Inner write field
  static constexpr auto scl_WriteField = [](decltype(tpValue) pValue) {
    if constexpr (!std::is_pointer_v<decltype(tpValue)>) {
      std::remove_const_t<decltype(pValue)> mask = 0;
      if (sc_ShortFormFlag & tpAccess) {
        for (uint8_t i = 0; i < (sizeof(decltype(pValue)) * 8); i += sc_Size) {
          if ((tpValue & (static_cast<decltype(pValue)>(1UL) << i))) {
            mask |= (tpValue & (pValue << i));
          }
        }
      } else {
        mask = pValue << sc_Offset;
      }
      return mask;
    } else {
      return 0;
    }
  };

  // Cast value to void * if pointer
  template <const auto pVal> struct pointer_cast final {
    static constexpr auto value = pVal;
  };

  template <auto *pVal> struct pointer_cast<pVal> final {
    static constexpr auto value = static_cast<void *>(pVal);
  };

public:
  struct FieldT;
  using Register = T;                         // Type of the register which contains the field
  static constexpr auto sc_Value = tpValue;   // The field value
  static constexpr auto sc_Access = tpAccess; // The field access mode

  /**
   * @brief Operator '|' to make 'or'  with field objects
   *
   * @constraints:  1) Value should be Field type
   *                2) Fields should belong to the same register
   *
   * @tparam Value The value that should be 'or' with the source value
   * @return Field<Register, (sc_Value | Value::sc_Value), (sc_Access & Value::sc_Access), sc_Size, sc_Number> The new
   * produced type
   */
  template <typename Value>
  requires field<Value> && std::is_same_v<typename Value::Register, Register>
  consteval auto operator|(const Value) const noexcept
      -> Field<Register, (sc_Value | Value::sc_Value), (sc_Access & Value::sc_Access), sc_Size, sc_Number> {
    static_assert(!(sc_Value & Value::sc_Value), "Peripheral field [ operator | ] Some bits of the operands are the same!");
    return {};
  }

  /**
   * @brief Operator '~' for '&=' operation (reset bit). Only for the compatibility.
   *
   * @return Field<Register, sc_Value, sc_Access, sc_Size, sc_Number>  the new produced type
   */
  consteval auto operator~() const noexcept -> Field<Register, sc_Value, sc_Access, sc_Size, sc_Number> { return {}; }

  /**
   * @brief Operator '[]' to create the same fields in the register
   *
   * @constraints:  1) FieldNumber should be RegVal type
   *                2) The field should be multiplied in the register
   *                3) FieldNumber should fit in the number of fields
   *
   * @tparam FieldNumber The field number of the same fields in the register
   * @return Field<Register, scl_FormField(sc_Value, FieldNumber::sc_Value, FieldNumber::sc_Offset *sc_Size),
   * (scl_isCompound(FieldNumber::sc_Value) | sc_Access), sc_Size, sc_Number> The new produced type
   */
  template <typename FieldNumber>
  requires val_valid::reg_val<FieldNumber> && (sc_Number > 1) && (FieldNumber::sc_Offset <= sc_Number)
  consteval auto operator[](const FieldNumber) const noexcept
      -> Field<Register, scl_FormField(sc_Value, FieldNumber::sc_Value, FieldNumber::sc_Offset), (scl_isCompound(FieldNumber::sc_Value) | sc_Access),
               sc_Size, sc_Number> {
    return {};
  }

  /**
   * @brief Operator '()' to create multi-bit fields
   *
   * @constraints:  1) BitNumber should be RegVal type
   *
   * @tparam BitNumber The value should be written in the current field.
   * @return Field<Register, scl_WriteField(BitNumber::sc_Value), sc_Access, sc_Size, sc_Number> The new produced typ
   */
  template <typename BitNumber>
  requires val_valid::reg_val<BitNumber> && (!BitNumber::sc_IsPointer)
  consteval auto operator()(const BitNumber) const noexcept -> Field<Register, scl_WriteField(BitNumber::sc_Value), sc_Access, sc_Size, sc_Number> {

    // Check size of the value
    constexpr auto cl_MaxValue = []() {
      std::remove_const_t<decltype(sc_Value)> maxValue = 0;
      for (unsigned int i = 0; i < sc_Size; i++) {
        maxValue |= (static_cast<decltype(maxValue)>(1UL) << i);
      }
      return maxValue;
    }();

    static_assert((BitNumber::sc_Value <= cl_MaxValue), "Peripheral field [ operator () ] The bit number was overflowed!");
    return {};
  }

  /**
   * @brief Overload operator for the compile-time pointer (look at the main overload)
   */
  template <typename BitNumber>
  requires val_valid::reg_val<BitNumber> && (BitNumber::sc_IsPointer)
  consteval auto operator()(const BitNumber) const noexcept
      -> Field<Register, pointer_cast<BitNumber::sc_Value>::value, sc_Access, sc_Size, sc_Number> {
    static_assert((8 * sizeof(void *) == sc_Size), "Peripheral field [ operator () ] The register should be fit enough to store address!");
    return {};
  }

  /**
   * @brief Comparison operator overload to check if some bits are set
   *        Can be performed in compile-time
   *
   * @constraints:  The field should be compared as the lhs, the value as rhs (on purpose)
   *
   * @param value Value that was read from the register
   * @return true  The condition is true
   * @return false The condition is false
   */
  [[nodiscard]] inline constexpr bool operator==(const Register::Size value) const noexcept { return (sc_Value == value); }
  [[nodiscard]] inline constexpr bool operator!=(const Register::Size value) const noexcept { return (sc_Value != value); }
};

/**
 * @brief Register class with data and operations with it
 *
 * @tparam tpAddress The address of the register
 * @tparam tpAccess The access mode for the register
 * @tparam SizeT The size type of the register
 * @tparam FieldT The type of field according the register
 * @tparam tpRegNumber The quantity of the same registers in the array
 * @tparam tpStep The step between the same registers in the array
 *
 */
template <const RegisterAddress tpAddress, const uint8_t tpAccess, typename SizeT, typename FieldT, const uint16_t tpRegNumber = 1,
          const uint16_t tpStep = sizeof(SizeT)>
class Register final {
  static constexpr auto sc_Address = tpAddress;          // The register address
  static constexpr auto sc_Access = tpAccess;            // The register access mode
  static constexpr auto sc_RegisterNumber = tpRegNumber; // The quantity of the consecutive registers
  static constexpr auto sc_Step = tpStep;

  // Inner function to get bit-band address
  template <typename Value> static consteval auto get_bit_band_address(const Value) {
    if constexpr (BIT_BAND_MODE) {
      constexpr RegisterAddress bitBandAddress = bit_band_addr(sc_Address, Value::sc_Value);
      return bitBandAddress;
    }
    return sc_Address;
  }

public:
  using Size = SizeT;   // Type of the value
  using Field = FieldT; // Type to identify field

  /**
   * @brief 'Set' or '|=' for the register (with bit-band)
   *
   * @constraints:  1) Value should be Field type
   *                2) The register should have the field (Value)
   *                3) Access mode for the register and the field should be AccessMode::SET
   *
   * @tparam Value The value (Field type) should be set
   *
   */
  template <typename Value>
  requires field<Value> && (std::is_same_v<Register::Field, typename Value::Register::Field>) &&
           (static_cast<bool>(Value::sc_Access & sc_Access & AccessMode::SET))
  inline void operator|=(const Value) const noexcept {
    constexpr auto bitBandAddress = get_bit_band_address(Value{});
    if constexpr (sc_Address != bitBandAddress) {
      *reinterpret_cast<volatile Size *>(bitBandAddress) = 1;
    } else {
      *reinterpret_cast<volatile Size *>(sc_Address) = *reinterpret_cast<volatile Size *>(sc_Address) | Value::sc_Value;
    }
  }

  /**
   * @brief 'Reset' or '&=' for the register (with bit-band)
   *
   * @constraints:  1) Value should be Field type
   *                2) The register should have the field (Value)
   *                3) Access mode for the register and the field should be AccessMode::RESET
   *
   * @tparam Value The value (Field type) should be reset
   *
   */
  template <typename Value>
  requires field<Value> && (std::is_same_v<Register::Field, typename Value::Register::Field>) &&
           (static_cast<bool>(Value::sc_Access & sc_Access & AccessMode::RESET))
  inline void operator&=(const Value) const noexcept {
    constexpr auto bitBandAddress = get_bit_band_address(Value{});
    if constexpr (sc_Address != bitBandAddress) {
      *reinterpret_cast<volatile Size *>(bitBandAddress) = 0;
    } else {
      *reinterpret_cast<volatile Size *>(sc_Address) = *reinterpret_cast<volatile Size *>(sc_Address) & ~Value::sc_Value;
    }
  }

  /**
   * @brief 'Assign' or '=' for the register
   *
   * @constraints:  1) Value should be Field type
   *                2) The register should have the field (Value)
   *                3) Access mode for the register and the field should be AccessMode::ASSIGN
   *
   * @tparam Value The value (Field type) should be assigned
   *
   */
  template <typename Value>
  requires field<Value> && (std::is_same_v<Register::Field, typename Value::Register::Field>) &&
           (static_cast<bool>(Value::sc_Access & sc_Access & AccessMode::ASSIGN))
  inline void operator=(const Value) const noexcept {
    *reinterpret_cast<volatile Size *>(sc_Address) = Value::sc_Value;
  }

  /**
   * @brief 'Toggle' or '^=' for the register
   *
   * @constraints:  1) Value should be Field type
   *                2) The register should have the field (Value)
   *                3) Access mode for the register and the field should be AccessMode::TOGGLE
   *
   * @tparam Value The value (Field type) should be toggled
   *
   */
  template <typename Value>
  requires field<Value> && (std::is_same_v<Register::Field, typename Value::Register::Field>) &&
           (static_cast<bool>(Value::sc_Access & sc_Access & AccessMode::TOGGLE))
  inline void operator^=(const Value) const noexcept {
    *reinterpret_cast<volatile Size *>(sc_Address) = *reinterpret_cast<volatile Size *>(sc_Address) ^ Value::sc_Value;
  }

  /**
   * @brief 'Read bit' or '&' for the register
   *
   * @constraints:  1) Value should be Field type
   *                2) The register should have the field (Value)
   *                3) Access mode for the register and the field should be AccessMode::READ
   *
   * @tparam Value The value (Field type) should be read
   *
   */
  template <typename Value>
  requires field<Value> && (std::is_same_v<Register::Field, typename Value::Register::Field>) &&
           (static_cast<bool>(Value::sc_Access & sc_Access & AccessMode::READ))
  inline auto operator&(const Value) const noexcept {
    // Check for only one bit is set or Value is not zero (return bool in this case)
    if constexpr (Value::sc_Value & (Value::sc_Value - 1)) {
      return *reinterpret_cast<volatile Size *>(sc_Address) & Value::sc_Value;
    } else {
      return static_cast<bool>(*reinterpret_cast<volatile Size *>(sc_Address) & Value::sc_Value);
    }
  }

  /**
   * @brief 'Read' or '*' for the register
   *
   * @constraints:  1) Access mode for the register should be AccessMode::READ
   *
   * @return SizeT The value is currently stored in the register
   */
  inline Size operator*() const noexcept
  requires(static_cast<bool>(sc_Access &AccessMode::READ))
  {
    return *reinterpret_cast<volatile Size *>(sc_Address);
  }

  /**
   * @brief Dynamic 'Assign' or '=' for the register (dynamic bytes in the buffer, pointers for DMA, et cetera)
   *
   * @constraints:  1) Value should fit the concept register_value
   *                2) Access mode for the register should be AccessMode::ASSIGN
   *
   * @tparam Value register_value type
   * @param value  [in] The value (dynamic) should be assigned
   *
   */
  template <typename Value>
  requires val_valid::register_value<Value> && (static_cast<bool>(sc_Access & AccessMode::ASSIGN))
  inline void operator=(const Value value) const noexcept {
    if constexpr (std::is_pointer_v<Value>) {
      *reinterpret_cast<volatile Size *>(sc_Address) = reinterpret_cast<Size>(value);
    } else {
      *reinterpret_cast<volatile Size *>(sc_Address) = static_cast<Size>(value);
    }
  }

  /**
   * @brief 'Get Address' or '&' for the register
   *
   * @return constexpr SizeT The const address of the register
   */
  inline consteval Size operator&() { return sc_Address; }

  /**
   * @brief Operator '[]' to create the calculate the exact address of the register in the registers array
   *
   * @constraints:  1) Num should be RegVal type
   *                2) Value of Num should fit to the quantity of the same registers
   *
   * @tparam Num the number of the register
   * @return Register<sc_Address + (Num::sc_Value * sizeof(Size)), sc_Access, Size, Field, sc_RegisterNumber> The
   * new produced type
   */
  template <typename Num>
  requires val_valid::reg_val<Num> && (Num::sc_Value < sc_RegisterNumber)
  inline consteval auto operator[](const Num) const noexcept
      -> Register<sc_Address + (Num::sc_Value * sc_Step), sc_Access, Size, Field, sc_RegisterNumber, sc_Step> {
    return {};
  }
};
} // namespace cpp_register
