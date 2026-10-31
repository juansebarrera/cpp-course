#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "cal/stats.hpp"

TEST_CASE("mean calcula el promedio", "[stats]") {
    REQUIRE(cal::mean({1.0, 2.0, 3.0}) == Catch::Approx(2.0));
    REQUIRE(cal::mean({}) == Catch::Approx(0.0));
}

TEST_CASE("median soporta par e impar", "[stats]") {
    REQUIRE(cal::median({3.0, 1.0, 2.0}) == Catch::Approx(2.0));
    REQUIRE(cal::median({4.0, 1.0, 3.0, 2.0}) == Catch::Approx(2.5));
}

TEST_CASE("median no modifica el vector del llamador", "[stats]") {
    const std::vector<double> values{9.0, 1.0, 5.0};
    const auto copy = values;
    static_cast<void>(cal::median(values));
    REQUIRE(values == copy);
}
