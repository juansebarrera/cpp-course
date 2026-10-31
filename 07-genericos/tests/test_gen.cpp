#include <cstddef>
#include <string>
#include <vector>

#include "gen/gen.hpp"
#include "mini_test.hpp"

TEST_CASE(clamp_funciona_con_enteros) {
    CHECK_EQ(gen::clamp_value(15, 0, 10), 10);
    CHECK_EQ(gen::clamp_value(-5, 0, 10), 0);
    CHECK_EQ(gen::clamp_value(5, 0, 10), 5);
}

TEST_CASE(clamp_funciona_con_doubles) {
    CHECK_EQ(gen::clamp_value(2.5, 0.0, 1.0), 1.0);
    CHECK_EQ(gen::clamp_value(-0.5, 0.0, 1.0), 0.0);
}

TEST_CASE(box_guarda_y_actualiza) {
    gen::Box<std::string> box("hola");
    CHECK_EQ(box.get(), "hola");
    box.set("adios");
    CHECK_EQ(box.get(), "adios");
}

TEST_CASE(sum_all_con_varios_tipos) {
    CHECK_EQ((gen::sum_all<int>({1, 2, 3})), 6);
    CHECK_EQ((gen::sum_all<std::size_t>({1, 2, 3})), std::size_t{6});
    CHECK_EQ(gen::sum_all<double>({}), 0.0);
    CHECK(gen::sum_all<double>({0.5, 0.25}) > 0.74);
}

TEST_CASE(sum_all_de_vector_vacio_es_cero) {
    const std::vector<int> empty;
    CHECK_EQ(gen::sum_all(empty), 0);
}
