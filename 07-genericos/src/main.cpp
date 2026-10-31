#include <iostream>
#include <string>
#include <vector>

#include "gen/gen.hpp"

int main() {
    std::cout << "clamp(15, 0, 10) = " << gen::clamp_value(15, 0, 10) << '\n';
    std::cout << "clamp(2.5, 0.0, 1.0) = " << gen::clamp_value(2.5, 0.0, 1.0) << '\n';

    gen::Box<std::string> box("C++");
    std::cout << "box = " << box.get() << '\n';
    box.set("genericos");
    std::cout << "box = " << box.get() << '\n';

    const std::vector<int> ints{1, 2, 3, 4};
    const std::vector<double> doubles{0.5, 1.5, 2.0};
    std::cout << "sum ints = " << gen::sum_all(ints) << '\n';
    std::cout << "sum doubles = " << gen::sum_all(doubles) << '\n';
    return 0;
}
