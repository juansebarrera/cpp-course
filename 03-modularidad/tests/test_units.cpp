#include "mini_test.hpp"
#include "units/units.hpp"

TEST_CASE(km_a_millas_es_aproximado) {
    CHECK(units::almost_equal(units::km_to_miles(10.0), 6.21371, 1e-4));
    CHECK(units::almost_equal(units::km_to_miles(0.0), 0.0));
}

TEST_CASE(conversion_ida_y_vuelta) {
    const double km = 42.0;
    CHECK(units::almost_equal(units::miles_to_km(units::km_to_miles(km)), km, 1e-9));
}

TEST_CASE(celsius_a_fahrenheit_en_puntos_conocidos) {
    CHECK(units::almost_equal(units::celsius_to_fahrenheit(0.0), 32.0));
    CHECK(units::almost_equal(units::celsius_to_fahrenheit(100.0), 212.0));
    CHECK(units::almost_equal(units::celsius_to_fahrenheit(-40.0), -40.0));
}

TEST_CASE(fahrenheit_a_celsius_en_puntos_conocidos) {
    CHECK(units::almost_equal(units::fahrenheit_to_celsius(212.0), 100.0));
    CHECK(units::almost_equal(units::fahrenheit_to_celsius(32.0), 0.0));
}

TEST_CASE(almost_equal_respeta_el_epsilon) {
    CHECK(units::almost_equal(1.0, 1.0 + 1e-10, 1e-9));
    CHECK(!units::almost_equal(1.0, 1.1, 1e-9));
}
