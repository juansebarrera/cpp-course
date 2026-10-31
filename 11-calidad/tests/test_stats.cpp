#include <cmath>

#include "cal/stats.hpp"
#include "mini_test.hpp"

namespace {

bool close_to(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) <= epsilon;
}

}  // namespace

TEST_CASE(media_de_vector_vacio_es_cero) {
    CHECK_EQ(cal::mean({}), 0.0);
}

TEST_CASE(media_calcula_el_promedio) {
    CHECK(close_to(cal::mean({1.0, 2.0, 3.0}), 2.0));
    CHECK(close_to(cal::mean({10.0}), 10.0));
    CHECK(close_to(cal::mean({-2.0, 2.0}), 0.0));
}

TEST_CASE(mediana_con_cantidad_impar) {
    CHECK(close_to(cal::median({3.0, 1.0, 2.0}), 2.0));
    CHECK(close_to(cal::median({5.0}), 5.0));
}

TEST_CASE(mediana_con_cantidad_par) {
    CHECK(close_to(cal::median({4.0, 1.0, 3.0, 2.0}), 2.5));
}

TEST_CASE(mediana_de_vector_vacio_es_cero) {
    CHECK_EQ(cal::median({}), 0.0);
}

TEST_CASE(varianza_poblacional) {
    CHECK(close_to(cal::variance({2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0}), 4.0));
    CHECK_EQ(cal::variance({}), 0.0);
    CHECK(close_to(cal::variance({7.0}), 0.0));
}
