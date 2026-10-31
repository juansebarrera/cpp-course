#include <memory>
#include <numbers>

#include "mini_test.hpp"
#include "poo/poo.hpp"

namespace {

bool nearly_equal(double a, double b) {
    const double epsilon = 1e-9;
    const double diff = a > b ? a - b : b - a;
    return diff <= epsilon;
}

}  // namespace

TEST_CASE(circulo_calcula_su_area) {
    const poo::Circle circle(2.0);
    CHECK(nearly_equal(circle.area(), 4.0 * std::numbers::pi));
    CHECK_EQ(circle.name(), "circulo");
}

TEST_CASE(rectangulo_calcula_su_area) {
    const poo::Rectangle rectangle(3.0, 4.0);
    CHECK(nearly_equal(rectangle.area(), 12.0));
    CHECK_EQ(rectangle.name(), "rectangulo");
}

TEST_CASE(total_area_suma_polimorficamente) {
    std::vector<std::unique_ptr<poo::Shape>> shapes;
    shapes.push_back(std::make_unique<poo::Circle>(1.0));
    shapes.push_back(std::make_unique<poo::Rectangle>(2.0, 5.0));

    CHECK(nearly_equal(poo::total_area(shapes), std::numbers::pi + 10.0));
}

TEST_CASE(total_area_de_lista_vacia_es_cero) {
    const std::vector<std::unique_ptr<poo::Shape>> shapes;
    CHECK_EQ(poo::total_area(shapes), 0.0);
}
