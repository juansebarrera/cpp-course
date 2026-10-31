#include "func/func.hpp"
#include "mini_test.hpp"

TEST_CASE(swap_intercambia_por_referencia) {
    int a = 1;
    int b = 2;
    func::swap_values(a, b);
    CHECK_EQ(a, 2);
    CHECK_EQ(b, 1);
}

TEST_CASE(max_of_con_dos_y_tres_argumentos) {
    CHECK_EQ(func::max_of(3, 8), 8);
    CHECK_EQ(func::max_of(8, 3), 8);
    CHECK_EQ(func::max_of(1, 5, 3), 5);
    CHECK_EQ(func::max_of(-1, -5, -3), -1);
}

TEST_CASE(sum_recorre_el_vector) {
    CHECK_EQ(func::sum({}), 0);
    CHECK_EQ(func::sum({1, 2, 3}), 6);
    CHECK_EQ(func::sum({-4, 4}), 0);
}

TEST_CASE(shout_modifica_la_cadena_original) {
    std::string text = "hola";
    func::shout(text);
    CHECK_EQ(text, "HOLA");
}

TEST_CASE(repeated_repites_y_controla_el_limite) {
    CHECK_EQ(func::repeated("ab", 3), "ababab");
    CHECK_EQ(func::repeated("x", 0), "");
    CHECK_EQ(func::repeated("x", -5), "");
}
