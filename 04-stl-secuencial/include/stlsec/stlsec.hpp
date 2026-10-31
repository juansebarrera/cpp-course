#pragma once

#include <string>
#include <vector>

namespace stlsec {

std::vector<int> evens(const std::vector<int>& values);
std::vector<int> sorted_desc(std::vector<int> values);
int total(const std::vector<int>& values);
std::vector<std::string> containing(const std::vector<std::string>& words,
                                    const std::string& needle);

}  // namespace stlsec
