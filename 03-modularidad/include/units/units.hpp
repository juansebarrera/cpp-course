#pragma once

namespace units {

double km_to_miles(double km);
double miles_to_km(double miles);
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
bool almost_equal(double a, double b, double epsilon = 1e-9);

}  // namespace units
