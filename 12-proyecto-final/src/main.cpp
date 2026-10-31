#include <iostream>
#include <string>

#include "agenda/agenda.hpp"

namespace {

void print_contacts(const agenda::Agenda& book) {
    if (book.size() == 0) {
        std::cout << "(agenda vacia)\n";
        return;
    }
    for (const agenda::Contact& contact : book.contacts()) {
        std::cout << "- " << contact.name << " | " << contact.email << " | " << contact.age
                  << " anios\n";
    }
}

std::string read_line(const std::string& prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}

int read_age(const std::string& prompt) {
    const std::string line = read_line(prompt);
    try {
        return std::stoi(line);
    } catch (const std::exception&) {
        return -1;
    }
}

}  // namespace

int main() {
    agenda::Agenda book;
    bool running = true;

    while (running) {
        std::cout << "\n=== Agenda ===\n"
                  << "1) Anadir contacto\n"
                  << "2) Listar contactos\n"
                  << "3) Buscar por nombre\n"
                  << "4) Eliminar contacto\n"
                  << "0) Salir\n";

        const std::string option = read_line("Opcion: ");
        if (option == "1") {
            agenda::Contact contact;
            contact.name = read_line("Nombre: ");
            contact.email = read_line("Email: ");
            contact.age = read_age("Edad: ");
            if (contact.name.empty() || contact.email.empty() || contact.age < 0) {
                std::cout << "Datos invalidos, no se anadio el contacto\n";
            } else if (!book.add(contact)) {
                std::cout << "Ya existe un contacto con ese nombre\n";
            } else {
                std::cout << "Contacto anadido\n";
            }
        } else if (option == "2") {
            print_contacts(book);
        } else if (option == "3") {
            const auto found = book.find(read_line("Nombre a buscar: "));
            if (found.has_value()) {
                std::cout << found->name << " | " << found->email << " | " << found->age
                          << " anios\n";
            } else {
                std::cout << "No encontrado\n";
            }
        } else if (option == "4") {
            const bool removed = book.remove(read_line("Nombre a eliminar: "));
            std::cout << (removed ? "Eliminado\n" : "No encontrado\n");
        } else if (option == "0" || option.empty()) {
            running = false;
        } else {
            std::cout << "Opcion no valida\n";
        }
    }

    std::cout << "Hasta luego. Contactos en memoria: " << book.size() << '\n';
    return 0;
}
