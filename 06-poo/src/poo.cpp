#include "poo/poo.hpp"

#include <numbers>

namespace poo {

Circle::Circle(double radius) : radius_(radius) {}

double Circle::area() const {
    return std::numbers::pi * radius_ * radius_;
}

std::string Circle::name() const {
    return "circulo";
}

Rectangle::Rectangle(double width, double height) : width_(width), height_(height) {}

double Rectangle::area() const {
    return width_ * height_;
}

std::string Rectangle::name() const {
    return "rectangulo";
}

double total_area(const std::vector<std::unique_ptr<Shape>>& shapes) {
    double total = 0.0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

}  // namespace poo
