#include "mini_test.hpp"
#include "stlsec/stlsec.hpp"

TEST_CASE(evens_filtra_y_conserva_el_orden) {
    CHECK(stlsec::evens({}).empty());
    CHECK(stlsec::evens({1, 3, 5}).empty());
    CHECK((stlsec::evens({2, 4, 6}) == std::vector<int>{2, 4, 6}));
    CHECK((stlsec::evens({5, 2, -8, 7, 0}) == std::vector<int>{2, -8, 0}));
}

TEST_CASE(sorted_desc_ordena_sin_modificar_el_original) {
    const std::vector<int> original{3, 1, 2};
    CHECK((stlsec::sorted_desc(original) == std::vector<int>{3, 2, 1}));
    CHECK((original == std::vector<int>{3, 1, 2}));
}

TEST_CASE(total_suma_todos_los_elementos) {
    CHECK_EQ(stlsec::total({}), 0);
    CHECK_EQ(stlsec::total({1, 2, 3}), 6);
    CHECK_EQ(stlsec::total({-5, 5}), 0);
}

TEST_CASE(containing_filtra_por_subcadena) {
    const std::vector<std::string> words{"cpp", "cmake", "git", "gcc", "rust"};
    CHECK((stlsec::containing(words, "c") == std::vector<std::string>{"cpp", "cmake", "gcc"}));
    CHECK(stlsec::containing(words, "zz").empty());
    CHECK((stlsec::containing(words, "r") == std::vector<std::string>{"rust"}));
}
