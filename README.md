# C++ Reflection Struct Project

## Structure

- include/         # Public headers (e.g. refl_struct.hpp)
- src/             # Library/source files (if needed)
- tests/           # Unit and integration tests
- CMakeLists.txt   # CMake build configuration
- test_refl_struct.cpp # Example/test (move to tests/ for best practice)

## Build

```sh
mkdir -p build
cd build
cmake ..
cmake --build .
./test_refl_struct
```
