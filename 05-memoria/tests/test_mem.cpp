#include "mem/mem.hpp"
#include "mini_test.hpp"

TEST_CASE(buffer_se_crea_con_ceros) {
    mem::IntBuffer buffer(4);
    CHECK_EQ(buffer.size(), std::size_t{4});
    CHECK(!buffer.empty());
    CHECK_EQ(buffer[0], 0);
    CHECK_EQ(buffer.sum(), 0);
}

TEST_CASE(buffer_de_tamano_cero_es_valido) {
    mem::IntBuffer buffer(0);
    CHECK_EQ(buffer.size(), std::size_t{0});
    CHECK(buffer.empty());
    CHECK_EQ(buffer.sum(), 0);
}

TEST_CASE(buffer_permite_escribir_y_sumar) {
    mem::IntBuffer buffer(3);
    buffer[0] = 1;
    buffer[1] = 2;
    buffer[2] = 3;
    CHECK_EQ(buffer.sum(), 6);
}

TEST_CASE(la_copia_es_independiente) {
    mem::IntBuffer original(2);
    original[0] = 10;
    original[1] = 20;

    mem::IntBuffer copy = original;
    copy[0] = 99;

    CHECK_EQ(original[0], 10);
    CHECK_EQ(copy[0], 99);
    CHECK_EQ(copy.sum(), 119);
}

TEST_CASE(el_movimiento_transfiere_los_datos) {
    mem::IntBuffer source(3);
    source[0] = 7;
    source[1] = 8;
    source[2] = 9;

    mem::IntBuffer moved = std::move(source);
    CHECK_EQ(moved.size(), std::size_t{3});
    CHECK_EQ(moved.sum(), 24);
}
