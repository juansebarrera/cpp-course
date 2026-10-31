#include "units/units.hpp"

#include <cmath>

namespace units {

double km_to_miles(double km) {
    return km * 0.621371;
}

double miles_to_km(double miles) {
    return miles / 0.621371;
}

double celsius_to_fahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

bool almost_equal(double a, double b, double epsilon) {
    return std::fabs(a - b) <= epsilon;
}

}  // namespace units
