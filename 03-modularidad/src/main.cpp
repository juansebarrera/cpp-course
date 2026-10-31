#include <iomanip>
#include <iostream>

#include "units/units.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "10 km = " << units::km_to_miles(10.0) << " millas\n";
    std::cout << "10 millas = " << units::miles_to_km(10.0) << " km\n";
    std::cout << "0 C = " << units::celsius_to_fahrenheit(0.0) << " F\n";
    std::cout << "100 C = " << units::celsius_to_fahrenheit(100.0) << " F\n";
    std::cout << "212 F = " << units::fahrenheit_to_celsius(212.0) << " C\n";
    return 0;
}
