#include "fund/fund.hpp"

namespace fund {

int add(int a, int b) {
    return a + b;
}

int clamp(int value, int low, int high) {
    if (value < low) {
        return low;
    }
    if (value > high) {
        return high;
    }
    return value;
}

bool is_even(int value) {
    return value % 2 == 0;
}

std::string describe_age(int age) {
    if (age < 0) {
        return "edad invalida";
    }
    if (age < 13) {
        return "nino";
    }
    if (age < 18) {
        return "adolescente";
    }
    if (age < 65) {
        return "adulto";
    }
    return "senior";
}

}  // namespace fund
