#include <iostream>

#include "refl_struct.hpp"

__refl_struct(MyStruct, (int, a), (float, b), (const char*, c))

    int main() {
  static_assert(MyStruct::type_index(std::string_view("int")) == 0, "int should be at index 0");
  static_assert(MyStruct::type_index(std::string_view("float")) == 1, "float should be at index 1");
  static_assert(MyStruct::type_index(std::string_view("const char*")) == 2,
                "const char* should be at index 2");
  static_assert(MyStruct::type_index(std::string_view("double")) == -1,
                "double should not be found");
  std::cout << "Field count: " << MyStruct::field_count << "\n";
  for (size_t i = 0; i < MyStruct::field_count; ++i) {
    std::cout << "Field " << i << ": type=" << MyStruct::field_types[i]
              << ", name=" << MyStruct::field_names[i] << "\n";
  }
  std::cout << "Index of type 'int': " << MyStruct::type_index(std::string_view("int")) << "\n";
  std::cout << "Index of type 'float': " << MyStruct::type_index(std::string_view("float")) << "\n";
  std::cout << "Index of type 'const char*': "
            << MyStruct::type_index(std::string_view("const char*")) << "\n";
  std::cout << "Index of type 'double': " << MyStruct::type_index(std::string_view("double"))
            << "\n";
  return 0;
}
