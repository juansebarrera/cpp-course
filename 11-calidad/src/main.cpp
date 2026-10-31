#include <iomanip>
#include <iostream>
#include <vector>

#include "cal/stats.hpp"

int main() {
    const std::vector<double> values{2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "n = " << values.size() << '\n';
    std::cout << "media = " << cal::mean(values) << '\n';
    std::cout << "mediana = " << cal::median(values) << '\n';
    std::cout << "varianza = " << cal::variance(values) << '\n';
    return 0;
}
