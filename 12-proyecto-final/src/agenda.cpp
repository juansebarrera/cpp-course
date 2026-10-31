#include "agenda/agenda.hpp"

#include <algorithm>
#include <utility>

namespace agenda {

bool Agenda::add(Contact contact) {
    if (find(contact.name).has_value()) {
        return false;
    }
    contacts_.push_back(std::move(contact));
    return true;
}

std::optional<Contact> Agenda::find(const std::string& name) const {
    const auto it = std::find_if(contacts_.begin(), contacts_.end(),
                                 [&name](const Contact& contact) {
                                     return contact.name == name;
                                 });
    if (it == contacts_.end()) {
        return std::nullopt;
    }
    return *it;
}

bool Agenda::remove(const std::string& name) {
    const auto it = std::find_if(contacts_.begin(), contacts_.end(),
                                 [&name](const Contact& contact) {
                                     return contact.name == name;
                                 });
    if (it == contacts_.end()) {
        return false;
    }
    contacts_.erase(it);
    return true;
}

std::size_t Agenda::size() const {
    return contacts_.size();
}

const std::vector<Contact>& Agenda::contacts() const {
    return contacts_;
}

}  // namespace agenda
