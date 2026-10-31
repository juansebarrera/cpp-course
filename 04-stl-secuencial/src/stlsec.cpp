#include "stlsec/stlsec.hpp"

#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

namespace stlsec {

std::vector<int> evens(const std::vector<int>& values) {
    std::vector<int> result;
    std::copy_if(values.begin(), values.end(), std::back_inserter(result),
                 [](int value) { return value % 2 == 0; });
    return result;
}

std::vector<int> sorted_desc(std::vector<int> values) {
    std::sort(values.begin(), values.end(), std::greater<int>());
    return values;
}

int total(const std::vector<int>& values) {
    return std::accumulate(values.begin(), values.end(), 0);
}

std::vector<std::string> containing(const std::vector<std::string>& words,
                                    const std::string& needle) {
    std::vector<std::string> result;
    std::copy_if(words.begin(), words.end(), std::back_inserter(result),
                 [&needle](const std::string& word) {
                     return word.find(needle) != std::string::npos;
                 });
    return result;
}

}  // namespace stlsec
