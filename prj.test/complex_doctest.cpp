#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

void test_input(const std::string& inp) {
    std::istringstream istrm(inp);

    Complex t;
    istrm >> t;

    CHECK_MESSAGE(istrm.good(), inp);
}

void test_add(const auto& lhs, const auto& rhs, const auto& res) {
    CHECK(lhs + rhs == res);
    if (lhs + rhs != res) {
        std::cout << lhs << " + " << rhs << " = " << res << std::endl;
    }
}

void test_sub(const auto& lhs, const auto& rhs, const auto& res) {
    CHECK(lhs - rhs == res);
    if (lhs - rhs != res) {
        std::cout << lhs << " - " << rhs << " = " << res << std::endl;
    }
}

void test_mul(const auto& lhs, const auto& rhs, const auto& res) {
    CHECK(lhs * rhs == res);
    if (lhs * rhs != res) {
        std::cout << lhs << " * " << rhs << " = " << res << std::endl;
    }
}

void test_div(const auto& lhs, const auto& rhs, const auto& res) {
    bool run = rhs != 0 && lhs / rhs == res;
    CHECK(run);
    if (lhs / rhs != res) {
        std::cout << lhs << " / " << rhs << " = " << res << std::endl;
    }
}

void test_eq(const Complex& lhs, const Complex& rhs, const bool& res) {
    CHECK((lhs == rhs) == res);
    if ((lhs == rhs) != res) {
        std::cout << lhs << " == " << rhs << " -> " << res << std::endl;
    }
}

void test_not_eq(const Complex& lhs, const Complex& rhs, const bool& res) {
    CHECK((lhs != rhs) == res);
    if ((lhs != rhs) != res) {
        std::cout << lhs << " == " << rhs << " = " << res << std::endl;
    }
}

TEST_CASE("[complex] - ctor") {
    test_input("{1, 3}");
    test_input("{1 , -3}");
    test_input("{ 3 , 4}");
    test_input("{-1 ,-1}");

    test_add(Complex(1, 2), Complex(1, 2), Complex(2, 4));
    test_add(Complex(1, 2), 3, Complex(4, 2));
    test_add(10, Complex(-1, 2), Complex(9, 2));

    test_sub(Complex(1, 2), Complex(1, 2), Complex(0, 0));
    test_sub(Complex(1, 2), 2, Complex(-1, 2));
    test_sub(0, Complex(1, 2), Complex(-1, -2));

    test_mul(Complex(99, 100), 0, Complex(0, 0));
    test_mul(-2, Complex(1, 2), Complex(-2, -4));

    test_div(Complex(1, 2), 2, Complex(0.5, 1));

    test_eq(Complex(10, 2), Complex(10, 2), true);
    test_eq(Complex(99, 100), Complex(-99, 100), false);

    test_not_eq(Complex(1, 2), Complex(1, 2), false);
    test_not_eq(Complex(99, 100), Complex(-99, 100), true);
}