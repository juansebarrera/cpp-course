#include <iostream>

#include "hello/hello.hpp"

int main() {
    std::cout << hello::greeting() << '\n';
    std::cout << "Compilado con C++" << __cplusplus << '\n';
    return 0;
}
