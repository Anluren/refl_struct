add_executable(test_macro_pair tests/test_macro_pair.cpp)
target_link_libraries(test_macro_pair PRIVATE refl_struct)
cmake_minimum_required(VERSION 3.10)
project(refl_struct_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(refl_struct INTERFACE)
target_include_directories(refl_struct INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test_refl_struct tests/test_refl_struct.cpp)
target_link_libraries(test_refl_struct PRIVATE refl_struct)

add_executable(test_bigstruct tests/test_bigstruct.cpp)
target_link_libraries(test_bigstruct PRIVATE refl_struct)