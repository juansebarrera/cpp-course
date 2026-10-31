#include <string>

#include "mini_test.hpp"
#include "stlav/stlav.hpp"

TEST_CASE(word_counts_cuenta_repeticiones) {
    const auto counts = stlav::word_counts({"a", "b", "a", "c", "a"});
    CHECK_EQ(counts.size(), std::size_t{3});
    CHECK_EQ(counts.at("a"), 3);
    CHECK_EQ(counts.at("b"), 1);
}

TEST_CASE(word_counts_con_vector_vacio_esta_vacio) {
    const auto counts = stlav::word_counts({});
    CHECK(counts.empty());
}

TEST_CASE(keys_sorted_respeta_el_orden_del_map) {
    const auto counts = stlav::word_counts({"zeta", "alfa", "beta"});
    CHECK((stlav::keys_sorted(counts) == std::vector<std::string>{"alfa", "beta", "zeta"}));
}

TEST_CASE(map_filter_aplica_transformacion_y_filtro) {
    const std::vector<int> values{1, 2, 3, 4};
    const auto result = stlav::map_filter(values, [](int v) { return v * 10; },
                                          [](int v) { return v >= 30; });
    CHECK((result == std::vector<int>{30, 40}));
}

TEST_CASE(map_filter_con_funciones_vacias_devuelve_todo) {
    const std::vector<int> values{1, 2, 3};
    const auto result = stlav::map_filter(values, [](int v) { return v; },
                                          [](int) { return true; });
    CHECK(result == values);
}
