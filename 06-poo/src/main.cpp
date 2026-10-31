#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "poo/poo.hpp"

int main() {
    std::vector<std::unique_ptr<poo::Shape>> shapes;
    shapes.push_back(std::make_unique<poo::Circle>(2.0));
    shapes.push_back(std::make_unique<poo::Rectangle>(3.0, 4.0));
    shapes.push_back(std::make_unique<poo::Circle>(0.5));

    std::cout << std::fixed << std::setprecision(2);
    for (const auto& shape : shapes) {
        std::cout << shape->name() << ": area = " << shape->area() << '\n';
    }
    std::cout << "area total = " << poo::total_area(shapes) << '\n';
    return 0;
}
