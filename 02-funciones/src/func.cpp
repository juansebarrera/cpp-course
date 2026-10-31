#include "func/func.hpp"

#include <cctype>

namespace func {

void swap_values(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}

int max_of(int a, int b) {
    return a > b ? a : b;
}

int max_of(int a, int b, int c) {
    return max_of(max_of(a, b), c);
}

int sum(const std::vector<int>& values) {
    int total = 0;
    for (const int value : values) {
        total += value;
    }
    return total;
}

void shout(std::string& text) {
    for (char& ch : text) {
        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    }
}

std::string repeated(const std::string& text, int times) {
    std::string result;
    if (times <= 0) {
        return result;
    }
    result.reserve(text.size() * static_cast<std::size_t>(times));
    for (int i = 0; i < times; ++i) {
        result += text;
    }
    return result;
}

}  // namespace func
