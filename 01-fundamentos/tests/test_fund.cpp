#include "fund/fund.hpp"
#include "mini_test.hpp"

TEST_CASE(add_suma_positivos_y_negativos) {
    CHECK_EQ(fund::add(2, 3), 5);
    CHECK_EQ(fund::add(-2, 2), 0);
    CHECK_EQ(fund::add(-3, -4), -7);
}

TEST_CASE(clamp_recorta_a_los_limites) {
    CHECK_EQ(fund::clamp(15, 0, 10), 10);
    CHECK_EQ(fund::clamp(-1, 0, 10), 0);
    CHECK_EQ(fund::clamp(5, 0, 10), 5);
}

TEST_CASE(is_even_detecta_paridad) {
    CHECK(fund::is_even(0));
    CHECK(fund::is_even(42));
    CHECK(!fund::is_even(7));
    CHECK(!fund::is_even(-3));
}

TEST_CASE(describe_age_cubre_los_limites) {
    CHECK_EQ(fund::describe_age(-1), "edad invalida");
    CHECK_EQ(fund::describe_age(12), "nino");
    CHECK_EQ(fund::describe_age(13), "adolescente");
    CHECK_EQ(fund::describe_age(18), "adulto");
    CHECK_EQ(fund::describe_age(65), "senior");
}
