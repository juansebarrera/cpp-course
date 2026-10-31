#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace stlav {

std::map<std::string, int> word_counts(const std::vector<std::string>& words);
std::vector<std::string> keys_sorted(const std::map<std::string, int>& counts);
std::vector<int> map_filter(const std::vector<int>& values,
                            const std::function<int(int)>& transform,
                            const std::function<bool(int)>& keep);

}  // namespace stlav
