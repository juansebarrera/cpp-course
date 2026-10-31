#include <iostream>
#include <string>
#include <vector>

#include "err/err.hpp"

int main() {
    const std::vector<std::string> samples{"42", "  -7", "3.14", "abc", ""};
    for (const std::string& text : samples) {
        const auto parsed = err::parse_int(text);
        std::cout << '"' << text << "\" -> "
                  << (parsed.has_value() ? std::to_string(*parsed) : "invalido") << '\n';
    }

    try {
        std::cout << "10 / 2 = " << err::checked_div(10, 2) << '\n';
        std::cout << "1 / 0 = " << err::checked_div(1, 0) << '\n';
    } catch (const err::DivisionError& error) {
        std::cout << "Error controlado: " << error.what() << '\n';
    }
    return 0;
}
