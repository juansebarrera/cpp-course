#pragma once

#include <string>
#include <vector>

namespace func {

void swap_values(int& a, int& b);
int max_of(int a, int b);
int max_of(int a, int b, int c);
int sum(const std::vector<int>& values);
void shout(std::string& text);
std::string repeated(const std::string& text, int times);

}  // namespace func
