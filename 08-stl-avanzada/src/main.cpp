#include <iostream>
#include <string>
#include <vector>

#include "stlav/stlav.hpp"

int main() {
    const std::vector<std::string> words{"cpp", "git", "cpp", "cmake", "cpp", "git"};
    const auto counts = stlav::word_counts(words);

    std::cout << "frecuencias:\n";
    for (const auto& [word, count] : counts) {
        std::cout << "  " << word << ": " << count << '\n';
    }

    std::cout << "claves ordenadas:";
    for (const std::string& key : stlav::keys_sorted(counts)) {
        std::cout << ' ' << key;
    }
    std::cout << '\n';

    const std::vector<int> numbers{1, 2, 3, 4, 5, 6};
    const auto doubled_evens = stlav::map_filter(
        numbers, [](int value) { return value * 2; }, [](int value) { return value % 3 == 0; });

    std::cout << "doblados y divisibles por 3:";
    for (const int value : doubled_evens) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';
    return 0;
}
