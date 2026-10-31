#include "cal/stats.hpp"

#include <algorithm>
#include <cstddef>

namespace cal {

double mean(const std::vector<double>& values) {
    if (values.empty()) {
        return 0.0;
    }
    double total = 0.0;
    for (const double value : values) {
        total += value;
    }
    return total / static_cast<double>(values.size());
}

double median(std::vector<double> values) {
    if (values.empty()) {
        return 0.0;
    }
    const auto middle = values.size() / 2;
    std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(middle),
                     values.end());
    const double upper = values[middle];
    if (values.size() % 2 != 0) {
        return upper;
    }
    const double lower =
        *std::max_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(middle));
    return (lower + upper) / 2.0;
}

double variance(const std::vector<double>& values) {
    if (values.empty()) {
        return 0.0;
    }
    const double average = mean(values);
    double total = 0.0;
    for (const double value : values) {
        const double diff = value - average;
        total += diff * diff;
    }
    return total / static_cast<double>(values.size());
}

}  // namespace cal
