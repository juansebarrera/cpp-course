#pragma once

#include <string>

namespace fund {

int add(int a, int b);
int clamp(int value, int low, int high);
bool is_even(int value);
std::string describe_age(int age);

}  // namespace fund
