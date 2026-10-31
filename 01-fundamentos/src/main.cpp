#include <iostream>

#include "fund/fund.hpp"

int main() {
    int a = 0;
    int b = 0;

    std::cout << "Calculadora: introduce dos enteros\n";
    if (!(std::cin >> a >> b)) {
        std::cerr << "Entrada invalida\n";
        return 1;
    }

    std::cout << a << " + " << b << " = " << fund::add(a, b) << '\n';
    std::cout << "clamp(" << a << ", 0, 100) = " << fund::clamp(a, 0, 100) << '\n';
    std::cout << a << (fund::is_even(a) ? " es par" : " es impar") << '\n';
    std::cout << "Edad " << a << ": " << fund::describe_age(a) << '\n';
    return 0;
}
