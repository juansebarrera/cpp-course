#include "stlav/stlav.hpp"

namespace stlav {

std::map<std::string, int> word_counts(const std::vector<std::string>& words) {
    std::map<std::string, int> counts;
    for (const std::string& word : words) {
        ++counts[word];
    }
    return counts;
}

std::vector<std::string> keys_sorted(const std::map<std::string, int>& counts) {
    std::vector<std::string> keys;
    keys.reserve(counts.size());
    for (const auto& [word, count] : counts) {
        (void)count;
        keys.push_back(word);
    }
    return keys;
}

std::vector<int> map_filter(const std::vector<int>& values,
                            const std::function<int(int)>& transform,
                            const std::function<bool(int)>& keep) {
    std::vector<int> result;
    for (const int value : values) {
        const int transformed = transform(value);
        if (keep(transformed)) {
            result.push_back(transformed);
        }
    }
    return result;
}

}  // namespace stlav
