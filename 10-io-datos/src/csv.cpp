#include "io/csv.hpp"

#include <fstream>
#include <stdexcept>
#include <string>

namespace io {

namespace {

std::vector<std::string> split(const std::string& line, char separator) {
    std::vector<std::string> fields;
    std::string current;
    for (const char ch : line) {
        if (ch == separator) {
            fields.push_back(current);
            current.clear();
        } else {
            current.push_back(ch);
        }
    }
    fields.push_back(current);
    return fields;
}

}  // namespace

std::vector<Contact> read_csv(const std::filesystem::path& path) {
    std::ifstream input(path);
    if (!input) {
        throw std::runtime_error("no se pudo abrir " + path.string());
    }

    std::vector<Contact> contacts;
    std::string line;
    bool first_line = true;
    while (std::getline(input, line)) {
        if (first_line) {
            first_line = false;
            continue;
        }
        if (line.empty()) {
            continue;
        }
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        const auto fields = split(line, ',');
        if (fields.size() != 3) {
            throw std::runtime_error("linea CSV invalida: " + line);
        }

        Contact contact;
        contact.name = fields[0];
        contact.email = fields[1];
        contact.age = std::stoi(fields[2]);
        contacts.push_back(contact);
    }
    return contacts;
}

void write_csv(const std::filesystem::path& path, const std::vector<Contact>& contacts) {
    std::ofstream output(path, std::ios::trunc);
    if (!output) {
        throw std::runtime_error("no se pudo escribir " + path.string());
    }

    output << "name,email,age\n";
    for (const Contact& contact : contacts) {
        output << contact.name << ',' << contact.email << ',' << contact.age << '\n';
    }
}

}  // namespace io
