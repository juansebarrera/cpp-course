#include "err/err.hpp"
#include "mini_test.hpp"

TEST_CASE(parse_int_acepta_enteros_validos) {
    CHECK(err::parse_int("42").has_value());
    CHECK_EQ(err::parse_int("42").value(), 42);
    CHECK_EQ(err::parse_int("-7").value(), -7);
    CHECK_EQ(err::parse_int("0").value(), 0);
}

TEST_CASE(parse_int_rechaza_entradas_invalidas) {
    CHECK(!err::parse_int("").has_value());
    CHECK(!err::parse_int("abc").has_value());
    CHECK(!err::parse_int("12abc").has_value());
    CHECK(!err::parse_int("3.14").has_value());
    CHECK_EQ(err::parse_int("999999999999999999999"), std::nullopt);
}

TEST_CASE(checked_div_divide_con_normalidad) {
    CHECK_EQ(err::checked_div(10, 2), 5);
    CHECK_EQ(err::checked_div(-9, 3), -3);
    CHECK_EQ(err::checked_div(0, 5), 0);
}

TEST_CASE(checked_div_lanza_division_error) {
    bool lanzada = false;
    try {
        static_cast<void>(err::checked_div(1, 0));
    } catch (const err::DivisionError& error) {
        lanzada = true;
        CHECK_EQ(std::string(error.what()), "division por cero");
    }
    CHECK(lanzada);
}

TEST_CASE(checked_div_es_capturable_como_runtime_error) {
    bool lanzada = false;
    try {
        static_cast<void>(err::checked_div(1, 0));
    } catch (const std::runtime_error&) {
        lanzada = true;
    }
    CHECK(lanzada);
}
