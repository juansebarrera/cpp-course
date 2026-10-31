#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace io {

struct Contact {
    std::string name;
    std::string email;
    int age = 0;

    bool operator==(const Contact& other) const = default;
};

std::vector<Contact> read_csv(const std::filesystem::path& path);
void write_csv(const std::filesystem::path& path, const std::vector<Contact>& contacts);

}  // namespace io
