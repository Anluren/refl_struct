// Macro to apply another macro to each argument, passing the index and the argument (cleaner version)
#define __RELF_APPLY_INDEX_HELPER(m, i, a) m(i, a)
#define __RELF_APPLY_INDEX_1(m, a1) __RELF_APPLY_INDEX_HELPER(m, 0, a1)
#define __RELF_APPLY_INDEX_2(m, a1, a2) \
  __RELF_APPLY_INDEX_1(m, a1) __RELF_APPLY_INDEX_HELPER(m, 1, a2)
#define __RELF_APPLY_INDEX_3(m, a1, a2, a3) \
  __RELF_APPLY_INDEX_2(m, a1, a2) __RELF_APPLY_INDEX_HELPER(m, 2, a3)
#define __RELF_APPLY_INDEX_4(m, a1, a2, a3, a4) \
  __RELF_APPLY_INDEX_3(m, a1, a2, a3) __RELF_APPLY_INDEX_HELPER(m, 3, a4)
#define __RELF_APPLY_INDEX_5(m, a1, a2, a3, a4, a5) \
  __RELF_APPLY_INDEX_4(m, a1, a2, a3, a4) __RELF_APPLY_INDEX_HELPER(m, 4, a5)
#define __RELF_APPLY_INDEX_6(m, a1, a2, a3, a4, a5, a6) \
  __RELF_APPLY_INDEX_5(m, a1, a2, a3, a4, a5) __RELF_APPLY_INDEX_HELPER(m, 5, a6)
#define __RELF_APPLY_INDEX_7(m, a1, a2, a3, a4, a5, a6, a7) \
  __RELF_APPLY_INDEX_6(m, a1, a2, a3, a4, a5, a6) __RELF_APPLY_INDEX_HELPER(m, 6, a7)
#define __RELF_APPLY_INDEX_8(m, a1, a2, a3, a4, a5, a6, a7, a8) \
  __RELF_APPLY_INDEX_7(m, a1, a2, a3, a4, a5, a6, a7) __RELF_APPLY_INDEX_HELPER(m, 7, a8)
#define __RELF_APPLY_INDEX_9(m, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
  __RELF_APPLY_INDEX_8(m, a1, a2, a3, a4, a5, a6, a7, a8) __RELF_APPLY_INDEX_HELPER(m, 8, a9)
#define __RELF_APPLY_INDEX_10(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
  __RELF_APPLY_INDEX_9(m, a1, a2, a3, a4, a5, a6, a7, a8, a9) __RELF_APPLY_INDEX_HELPER(m, 9, a10)
// ... extend as needed up to 30
#define __RELF_APPLY_INDEX(macro, ...) __RELF_APPLY_INDEX_N(macro, __RELF_NARG(__VA_ARGS__), __VA_ARGS__)
#define __RELF_APPLY_INDEX_N(macro, N, ...) __RELF_APPLY_INDEX_N_(macro, N, __VA_ARGS__)
#define __RELF_APPLY_INDEX_N_(macro, N, ...) __RELF_APPLY_INDEX_##N(macro, __VA_ARGS__)
// Macro to apply another macro to each argument, passing an extra parameter
#define __RELF_APPLY1(macro, extra, ...) __RELF_APPLY1_N(macro, extra, __RELF_NARG(__VA_ARGS__), __VA_ARGS__)
#define __RELF_APPLY1_N(macro, extra, N, ...) __RELF_APPLY1_N_(macro, extra, N, __VA_ARGS__)
#define __RELF_APPLY1_N_(macro, extra, N, ...) __RELF_APPLY1_##N(macro, extra, __VA_ARGS__)

#define __RELF_APPLY1_1(m, e, a1) m(e, a1)
#define __RELF_APPLY1_2(m, e, a1, a2) m(e, a1) m(e, a2)
#define __RELF_APPLY1_3(m, e, a1, a2, a3) m(e, a1) m(e, a2) m(e, a3)
#define __RELF_APPLY1_4(m, e, a1, a2, a3, a4) m(e, a1) m(e, a2) m(e, a3) m(e, a4)
#define __RELF_APPLY1_5(m, e, a1, a2, a3, a4, a5) m(e, a1) m(e, a2) m(e, a3) m(e, a4) m(e, a5)
// ... repeat up to 30 as needed
#define __RELF_APPLY1_6(m, e, a1, a2, a3, a4, a5, a6) m(e, a1) m(e, a2) m(e, a3) m(e, a4) m(e, a5) m(e, a6)
#define __RELF_APPLY1_7(m, e, a1, a2, a3, a4, a5, a6, a7) m(e, a1) m(e, a2) m(e, a3) m(e, a4) m(e, a5) m(e, a6) m(e, a7)
#define __RELF_APPLY1_8(m, e, a1, a2, a3, a4, a5, a6, a7, a8) m(e, a1) m(e, a2) m(e, a3) m(e, a4) m(e, a5) m(e, a6) m(e, a7) m(e, a8)
#define __RELF_APPLY1_9(m, e, a1, a2, a3, a4, a5, a6, a7, a8, a9) m(e, a1) m(e, a2) m(e, a3) m(e, a4) m(e, a5) m(e, a6) m(e, a7) m(e, a8) m(e, a9)
#define __RELF_APPLY1_10(m, e, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) m(e, a1) m(e, a2) m(e, a3) m(e, a4) m(e, a5) m(e, a6) m(e, a7) m(e, a8) m(e, a9) m(e, a10)
// ... continue up to 30 if needed
// refl_struct.hpp
// Reflection macro for C++17 struct with up to 30 fields

#pragma once
#include <cstddef>
#include <string_view>
#include <tuple>

// Helper macros to extract type and name from (type, name)
#define __RELF_TYPE(pair) __RELF_TYPE_ pair
#define __RELF_TYPE_(type, name) type
#define __RELF_NAME(pair) __RELF_NAME_ pair
#define __RELF_NAME_(type, name) name

// Stringize helpers
#define __RELF_STR(s) #s
#define __RELF_TYPE_STR(pair) __RELF_TYPE_STR_ pair
#define __RELF_TYPE_STR_(type, name) #type
#define __RELF_NAME_STR(pair) __RELF_NAME_STR_ pair
#define __RELF_NAME_STR_(type, name) #name

// Macro to count arguments (up to 30)
#define __RELF_NARG_(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, \
                     _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, N, ...)    \
  N
#define __RELF_NARG(...)                                                                        \
  __RELF_NARG_(__VA_ARGS__, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, \
               13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

// Macro to apply another macro to each argument
#define __RELF_APPLY(macro, ...) __RELF_APPLY_N(macro, __RELF_NARG(__VA_ARGS__), __VA_ARGS__)
#define __RELF_APPLY_N(macro, N, ...) __RELF_APPLY_N_(macro, N, __VA_ARGS__)
#define __RELF_APPLY_N_(macro, N, ...) __RELF_APPLY_##N(macro, __VA_ARGS__)

#define __RELF_APPLY_1(m, a1) m(a1)
#define __RELF_APPLY_2(m, a1, a2) m(a1) m(a2)
#define __RELF_APPLY_3(m, a1, a2, a3) m(a1) m(a2) m(a3)
#define __RELF_APPLY_4(m, a1, a2, a3, a4) m(a1) m(a2) m(a3) m(a4)
#define __RELF_APPLY_5(m, a1, a2, a3, a4, a5) m(a1) m(a2) m(a3) m(a4) m(a5)
// ... repeat up to 30

#define __RELF_APPLY_6(m, a1, a2, a3, a4, a5, a6) m(a1) m(a2) m(a3) m(a4) m(a5) m(a6)
#define __RELF_APPLY_7(m, a1, a2, a3, a4, a5, a6, a7) m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7)
#define __RELF_APPLY_8(m, a1, a2, a3, a4, a5, a6, a7, a8) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8)
#define __RELF_APPLY_9(m, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9)
#define __RELF_APPLY_10(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10)
#define __RELF_APPLY_11(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11)
#define __RELF_APPLY_12(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12)
#define __RELF_APPLY_13(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13)
#define __RELF_APPLY_14(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14)
#define __RELF_APPLY_15(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15)
#define __RELF_APPLY_16(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16)
#define __RELF_APPLY_17(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17)                                                                      \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17)
#define __RELF_APPLY_18(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18)                                                                 \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18)
#define __RELF_APPLY_19(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19)                                                            \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19)
#define __RELF_APPLY_20(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20)                                                       \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20)
#define __RELF_APPLY_21(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21)                                                  \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21)
#define __RELF_APPLY_22(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22)                                             \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22)
#define __RELF_APPLY_23(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23)                                        \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23)
#define __RELF_APPLY_24(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23, a24)                                   \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23) m(a24)
#define __RELF_APPLY_25(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23, a24, a25)                              \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23) m(a24) m(a25)
#define __RELF_APPLY_26(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23, a24, a25, a26)                         \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23) m(a24) m(a25) m(a26)
#define __RELF_APPLY_27(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27)                    \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23) m(a24) m(a25) m(a26) m(a27)
#define __RELF_APPLY_28(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28)               \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23) m(a24) m(a25) m(a26) m(a27) m(a28)
#define __RELF_APPLY_29(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29)          \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23) m(a24) m(a25) m(a26) m(a27) m(a28)  \
          m(a29)
#define __RELF_APPLY_30(m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
                        a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30)     \
  m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10) m(a11) m(a12) m(a13) m(a14) m(a15) \
      m(a16) m(a17) m(a18) m(a19) m(a20) m(a21) m(a22) m(a23) m(a24) m(a25) m(a26) m(a27) m(a28)  \
          m(a29) m(a30)

// Member declaration macro
#define __RELF_MEMBER(pair) __RELF_TYPE(pair) __RELF_NAME(pair);

// String arrays for names and types
#define __RELF_NAME_STR_ITEM(pair) __RELF_NAME_STR(pair),
#define __RELF_TYPE_STR_ITEM(pair) __RELF_TYPE_STR(pair),

// Main struct macro

#define __refl_struct(STRUCT_NAME, ...)                              \
  struct STRUCT_NAME {                                               \
    __RELF_APPLY(__RELF_MEMBER, __VA_ARGS__)                         \
    static constexpr size_t field_count = __RELF_NARG(__VA_ARGS__);  \
    static constexpr std::string_view field_names[field_count] = {   \
        __RELF_APPLY(__RELF_NAME_STR_ITEM, __VA_ARGS__)};            \
    static constexpr std::string_view field_types[field_count] = {   \
        __RELF_APPLY(__RELF_TYPE_STR_ITEM, __VA_ARGS__)};            \
    static constexpr int type_index(std::string_view type_name) {    \
      for (size_t i = 0; i < field_count; ++i) {                     \
        if (field_types[i] == type_name) return static_cast<int>(i); \
      }                                                              \
      return -1;                                                     \
    }                                                                \
    static constexpr int field_index(std::string_view name) {        \
      for (size_t i = 0; i < field_count; ++i) {                     \
        if (field_names[i] == name) return static_cast<int>(i);      \
      }                                                              \
      return -1;                                                     \
    }                                                                \
  };

// Usage example:
// __refl_struct(MyStruct, (int, a), (float, b), (std::string, c))
// MyStruct::field_count, MyStruct::field_names, MyStruct::field_types
