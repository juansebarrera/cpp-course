#include <iostream>
#include <string>
#include <vector>

#include "stlsec/stlsec.hpp"

namespace {

void print_ints(const std::vector<int>& values) {
    for (const int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

void print_strings(const std::vector<std::string>& values) {
    for (const std::string& value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

}  // namespace

int main() {
    const std::vector<int> numbers{5, 2, 8, 1, 8, 4, 7};

    std::cout << "original: ";
    print_ints(numbers);

    std::cout << "pares: ";
    print_ints(stlsec::evens(numbers));

    std::cout << "ordenado desc: ";
    print_ints(stlsec::sorted_desc(numbers));

    std::cout << "total: " << stlsec::total(numbers) << '\n';

    const std::vector<std::string> words{"cpp", "cmake", "git", "gcc"};
    std::cout << "contienen 'c': ";
    print_strings(stlsec::containing(words, "c"));
    return 0;
}
