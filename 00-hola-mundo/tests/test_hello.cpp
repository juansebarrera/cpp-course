#include "hello/hello.hpp"
#include "mini_test.hpp"

TEST_CASE(greeting_no_esta_vacio) {
    CHECK(!hello::greeting().empty());
}

TEST_CASE(greeting_tiene_el_texto_esperado) {
    CHECK_EQ(hello::greeting(), "Hola, C++!");
}
