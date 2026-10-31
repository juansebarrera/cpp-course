#pragma once

#include <optional>
#include <stdexcept>
#include <string>

namespace err {

std::optional<int> parse_int(const std::string& text);

class DivisionError : public std::runtime_error {
public:
    explicit DivisionError(const std::string& message);
};

int checked_div(int numerator, int denominator);

}  // namespace err
