#include <filesystem>
#include <iostream>

#include "io/csv.hpp"

int main() {
    const std::filesystem::path path = "contacts_demo.csv";

    const std::vector<io::Contact> contacts{
        {"Ana", "ana@example.com", 28},
        {"Luis", "luis@example.com", 34},
        {"Marta", "marta@example.com", 41},
    };

    io::write_csv(path, contacts);
    std::cout << "Escritos " << contacts.size() << " contactos en " << path.string() << '\n';

    const auto loaded = io::read_csv(path);
    for (const io::Contact& contact : loaded) {
        std::cout << "- " << contact.name << " <" << contact.email << "> (" << contact.age
                  << ")\n";
    }
    return 0;
}
