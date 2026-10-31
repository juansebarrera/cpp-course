#include "agenda/agenda.hpp"
#include "mini_test.hpp"

TEST_CASE(agenda_empieza_vacia) {
    const agenda::Agenda book;
    CHECK_EQ(book.size(), std::size_t{0});
    CHECK(book.contacts().empty());
}

TEST_CASE(add_guarda_y_evita_duplicados) {
    agenda::Agenda book;
    CHECK(book.add({"Ana", "ana@example.com", 28}));
    CHECK_EQ(book.size(), std::size_t{1});
    CHECK(!book.add({"Ana", "otra@example.com", 30}));
    CHECK_EQ(book.size(), std::size_t{1});
}

TEST_CASE(find_devuelve_el_contacto_o_nullopt) {
    agenda::Agenda book;
    book.add({"Luis", "luis@example.com", 34});

    const auto found = book.find("Luis");
    CHECK(found.has_value());
    CHECK_EQ(found->email, "luis@example.com");
    CHECK_EQ(found->age, 34);

    CHECK(!book.find("Inexistente").has_value());
}

TEST_CASE(remove_elimina_solo_si_existe) {
    agenda::Agenda book;
    book.add({"Marta", "marta@example.com", 41});

    CHECK(book.remove("Marta"));
    CHECK_EQ(book.size(), std::size_t{0});
    CHECK(!book.remove("Marta"));
}

TEST_CASE(contacts_conserva_el_orden_de_insercion) {
    agenda::Agenda book;
    book.add({"B", "b@example.com", 2});
    book.add({"A", "a@example.com", 1});

    CHECK_EQ(book.contacts().size(), std::size_t{2});
    CHECK_EQ(book.contacts()[0].name, "B");
    CHECK_EQ(book.contacts()[1].name, "A");
}
