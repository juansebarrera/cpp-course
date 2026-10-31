#include <iostream>
#include <string>
#include <vector>

#include "func/func.hpp"

int main() {
    int a = 3;
    int b = 8;
    std::cout << "Antes: a=" << a << " b=" << b << '\n';
    func::swap_values(a, b);
    std::cout << "Despues: a=" << a << " b=" << b << '\n';

    const std::vector<int> numbers{4, 8, 15, 16, 23, 42};
    std::cout << "suma = " << func::sum(numbers) << '\n';
    std::cout << "max(3, 8) = " << func::max_of(3, 8) << '\n';
    std::cout << "max(3, 8, 5) = " << func::max_of(3, 8, 5) << '\n';

    std::string message = "aprendiendo c++";
    func::shout(message);
    std::cout << message << '\n';
    std::cout << func::repeated("ab", 3) << '\n';
    return 0;
}
