#include <cassert>
#include <iostream>
#include <string_view>

#include "refl_struct.hpp"

__refl_struct(BigStruct, (int, f1), (int, f2), (int, f3), (int, f4), (int, f5), (int, f6),
              (int, f7), (int, f8), (int, f9), (int, f10), (int, f11), (int, f12), (int, f13),
              (int, f14), (int, f15), (int, f16), (int, f17), (int, f18), (int, f19), (int, f20),
              (int, f21), (int, f22), (int, f23), (int, f24), (int, f25), (int, f26), (int, f27),
              (int, f28), (int, f29), (int, f30))

    int main() {
  static_assert(BigStruct::field_count == 30, "BigStruct should have 30 fields");
  for (size_t i = 0; i < BigStruct::field_count; ++i) {
    assert(BigStruct::field_types[i] == "int");
    assert(BigStruct::field_names[i].substr(0, 1) == "f");
  }
  std::cout << "BigStruct reflection test passed.\n";
  return 0;
}
