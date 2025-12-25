// refl_struct.hpp
// Reflection macro for C++17 struct with up to 30 fields
#pragma once

#include <cstddef>
#include <tuple>
#include <string_view>

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
#define __RELF_NARG_(\
     _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10,\
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,\
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, N, ...) N
#define __RELF_NARG(...) __RELF_NARG_(__VA_ARGS__,\
    30,29,28,27,26,25,24,23,22,21,20,\
    19,18,17,16,15,14,13,12,11,10,\
    9,8,7,6,5,4,3,2,1,0)

// Macro to apply another macro to each argument
#define __RELF_APPLY(macro, ...) __RELF_APPLY_N(macro, __RELF_NARG(__VA_ARGS__), __VA_ARGS__)
#define __RELF_APPLY_N(macro, N, ...) __RELF_APPLY_N_(macro, N, __VA_ARGS__)
#define __RELF_APPLY_N_(macro, N, ...) __RELF_APPLY_##N(macro, __VA_ARGS__)

#define __RELF_APPLY_1(m,a1)           m(a1)
#define __RELF_APPLY_2(m,a1,a2)        m(a1) m(a2)
#define __RELF_APPLY_3(m,a1,a2,a3)     m(a1) m(a2) m(a3)
#define __RELF_APPLY_4(m,a1,a2,a3,a4)  m(a1) m(a2) m(a3) m(a4)
#define __RELF_APPLY_5(m,a1,a2,a3,a4,a5) m(a1) m(a2) m(a3) m(a4) m(a5)
// ... repeat up to 30
#define __RELF_APPLY_6(m,a1,a2,a3,a4,a5,a6) m(a1) m(a2) m(a3) m(a4) m(a5) m(a6)
#define __RELF_APPLY_7(m,a1,a2,a3,a4,a5,a6,a7) m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7)
#define __RELF_APPLY_8(m,a1,a2,a3,a4,a5,a6,a7,a8) m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8)
#define __RELF_APPLY_9(m,a1,a2,a3,a4,a5,a6,a7,a8,a9) m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9)
#define __RELF_APPLY_10(m,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10) m(a1) m(a2) m(a3) m(a4) m(a5) m(a6) m(a7) m(a8) m(a9) m(a10)
// ... (expand up to 30 as needed)

// Member declaration macro
#define __RELF_MEMBER(pair) __RELF_TYPE(pair) __RELF_NAME(pair);

// String arrays for names and types
#define __RELF_NAME_STR_ITEM(pair) __RELF_NAME_STR(pair),
#define __RELF_TYPE_STR_ITEM(pair) __RELF_TYPE_STR(pair),

// Main struct macro
// Helper for constexpr string compare
#include <cstring>
namespace __refl_detail {
    constexpr bool str_eq(const char* a, const char* b) {
        while (*a && *b) { if (*a != *b) return false; ++a; ++b; }
        return *a == *b;
    }
    template <size_t N>
    constexpr int type_index(const char* const (&types)[N], const char* type_name, size_t i = 0) {
        return i == N ? -1 : (str_eq(types[i], type_name) ? static_cast<int>(i) : type_index(types, type_name, i + 1));
    }
}
#define __refl_struct(STRUCT_NAME, ...) \
struct STRUCT_NAME { \
    __RELF_APPLY(__RELF_MEMBER, __VA_ARGS__) \
    static constexpr size_t field_count = __RELF_NARG(__VA_ARGS__); \
    static constexpr const char* field_names[field_count] = { __RELF_APPLY(__RELF_NAME_STR_ITEM, __VA_ARGS__) }; \
    static constexpr const char* field_types[field_count] = { __RELF_APPLY(__RELF_TYPE_STR_ITEM, __VA_ARGS__) }; \
    static constexpr int type_index(const char* type_name) { \
        return __refl_detail::type_index(field_types, type_name); \
    } \
};

// Usage example:
// __refl_struct(MyStruct, (int, a), (float, b), (std::string, c))
// MyStruct::field_count, MyStruct::field_names, MyStruct::field_types
