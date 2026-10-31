#pragma once

#include <cstdio>
#include <functional>
#include <string>
#include <utility>
#include <vector>

namespace minitest {

struct Failure {
    std::string message;
};

using TestFn = std::function<void()>;

struct TestCase {
    const char* name;
    TestFn fn;
};

inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> tests;
    return tests;
}

struct Registrar {
    Registrar(const char* name, TestFn fn) { registry().push_back({name, std::move(fn)}); }
};

inline int run_all() {
    int failed = 0;
    for (const auto& test : registry()) {
        try {
            test.fn();
            std::printf("[ OK ] %s\n", test.name);
        } catch (const Failure& failure) {
            ++failed;
            std::printf("[FAIL] %s\n       %s\n", test.name, failure.message.c_str());
        }
    }
    const auto total = static_cast<int>(registry().size());
    std::printf("%d/%d tests passed\n", total - failed, total);
    return failed == 0 ? 0 : 1;
}

}  // namespace minitest

#define TEST_CASE(name)                                                        \
    static void test_##name();                                                 \
    static const minitest::Registrar registrar_##name(#name, test_##name);      \
    static void test_##name()

#define CHECK(condition)                                                                 \
    do {                                                                                 \
        if (!(condition)) {                                                              \
            throw minitest::Failure{std::string("CHECK failed: ") + #condition +         \
                                    " (" + __FILE__ + ":" + std::to_string(__LINE__) +    \
                                    ")"};                                                \
        }                                                                                \
    } while (false)

#define CHECK_EQ(actual, expected)                                                       \
    do {                                                                                 \
        if (!((actual) == (expected))) {                                                 \
            throw minitest::Failure{std::string("CHECK_EQ failed: ") + #actual +         \
                                    " == " + #expected + " (" + __FILE__ + ":" +         \
                                    std::to_string(__LINE__) + ")"};                     \
        }                                                                                \
    } while (false)
