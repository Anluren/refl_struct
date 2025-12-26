#include <iostream>
#include "refl_struct.hpp"

// This should expand to: int a;
FORWARD_PAIR(PRINT_TYPE_AND_NAME, (int, a))

int main() {
    a = 42;
    std::cout << "a = " << a << std::endl;
    return 0;
}
