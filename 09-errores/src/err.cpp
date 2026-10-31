#include "err/err.hpp"

namespace err {

std::optional<int> parse_int(const std::string& text) {
    if (text.empty()) {
        return std::nullopt;
    }
    try {
        std::size_t consumed = 0;
        const int value = std::stoi(text, &consumed);
        if (consumed != text.size()) {
            return std::nullopt;
        }
        return value;
    } catch (const std::exception&) {
        return std::nullopt;
    }
}

DivisionError::DivisionError(const std::string& message) : std::runtime_error(message) {}

int checked_div(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivisionError("division por cero");
    }
    return numerator / denominator;
}

}  // namespace err
