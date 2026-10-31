#pragma once

#include <cstddef>
#include <optional>
#include <string>
#include <vector>

namespace agenda {

struct Contact {
    std::string name;
    std::string email;
    int age = 0;

    bool operator==(const Contact& other) const = default;
};

class Agenda {
public:
    bool add(Contact contact);
    std::optional<Contact> find(const std::string& name) const;
    bool remove(const std::string& name);
    std::size_t size() const;
    const std::vector<Contact>& contacts() const;

private:
    std::vector<Contact> contacts_;
};

}  // namespace agenda
