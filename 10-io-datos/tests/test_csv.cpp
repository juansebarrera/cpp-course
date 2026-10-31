#include <filesystem>
#include <fstream>
#include <stdexcept>

#include "io/csv.hpp"
#include "mini_test.hpp"

namespace {

std::filesystem::path temp_file(const std::string& name) {
    return std::filesystem::temp_directory_path() / name;
}

}  // namespace

TEST_CASE(escribir_y_leer_conserva_los_datos) {
    const auto path = temp_file("cpp_course_contacts_roundtrip.csv");
    const std::vector<io::Contact> original{
        {"Ana", "ana@example.com", 28},
        {"Luis", "luis@example.com", 34},
    };

    io::write_csv(path, original);
    const auto loaded = io::read_csv(path);
    std::filesystem::remove(path);

    CHECK(loaded == original);
}

TEST_CASE(lista_vacia_escribe_solo_cabecera) {
    const auto path = temp_file("cpp_course_contacts_empty.csv");
    io::write_csv(path, {});
    const auto loaded = io::read_csv(path);
    std::filesystem::remove(path);

    CHECK(loaded.empty());
}

TEST_CASE(leer_un_archivo_inexistente_lanza) {
    const auto path = temp_file("cpp_course_no_existe.csv");
    std::filesystem::remove(path);

    bool lanzada = false;
    try {
        static_cast<void>(io::read_csv(path));
    } catch (const std::runtime_error&) {
        lanzada = true;
    }
    CHECK(lanzada);
}

TEST_CASE(linea_invalida_lanza) {
    const auto path = temp_file("cpp_course_contacts_bad.csv");
    {
        std::ofstream output(path);
        output << "name,email,age\n";
        output << "Ana,ana@example.com\n";
    }

    bool lanzada = false;
    try {
        static_cast<void>(io::read_csv(path));
    } catch (const std::runtime_error&) {
        lanzada = true;
    }
    std::filesystem::remove(path);
    CHECK(lanzada);
}
