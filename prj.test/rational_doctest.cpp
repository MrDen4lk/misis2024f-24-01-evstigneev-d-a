#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <iostream>

void test_input(const std::string& inp) {
    std::istringstream istrm(inp);

    Rational t;
    istrm >> t;

    CHECK_MESSAGE(istrm.good(), inp);
}

void test_add(const Rational& lhs, const Rational& rhs, const Rational& res) {
    CHECK(lhs + rhs == res);
    if (lhs + rhs != res) {
        std::cout << lhs << " + " << rhs << " = " << res << std::endl;
    }
}

void test_sub(const Rational& lhs, const Rational& rhs, const Rational& res) {
    CHECK(lhs - rhs == res);
    if (lhs - rhs != res) {
        std::cout << lhs << " - " << rhs << " = " << res << std::endl;
    }
}

void test_mul(const Rational& lhs, const Rational& rhs, const Rational& res) {
    CHECK(lhs * rhs == res);
    if (lhs * rhs != res) {
        std::cout << lhs << " * " << rhs << " = " << res << std::endl;
    }
}

void test_div(const Rational& lhs, const Rational& rhs, const Rational& res) {
    bool run = rhs != 0 && lhs / rhs == res;
    CHECK(run);
    if (lhs / rhs != res) {
        std::cout << lhs << " / " << rhs << " = " << res << std::endl;
    }
}

void test_bigger(const Rational& lhs, const Rational& rhs, const bool& res) {
    CHECK((lhs > rhs) == res);
    if ((lhs > rhs) != res) {
        std::cout << lhs << " > " << rhs << " -> " << res << std::endl;
    }
}

void test_e_bigger(const Rational& lhs, const Rational& rhs, const bool& res) {
    CHECK((lhs >= rhs) == res);
    if ((lhs >= rhs) != res) {
        std::cout << lhs << " >= " << rhs << " -> " << res << std::endl;
    }
}

void test_smoller(const Rational& lhs, const Rational& rhs, const bool& res) {
    CHECK((lhs < rhs) == res);
    if ((lhs < rhs) != res) {
        std::cout << lhs << " < " << rhs << " -> " << res << std::endl;
    }
}

void test_e_smoller(const Rational& lhs, const Rational& rhs, const bool& res) {
    CHECK((lhs <= rhs) == res);
    if ((lhs <= rhs) != res) {
        std::cout << lhs << " <= " << rhs << " -> " << res << std::endl;
    }
}

void test_eq(const Rational& lhs, const Rational& rhs, const bool& res) {
    CHECK((lhs == rhs) == res);
    if ((lhs == rhs) != res) {
        std::cout << lhs << " == " << rhs << " -> " << res << std::endl;
    }
}

void test_not_eq(const Rational& lhs, const Rational& rhs, const bool& res) {
    CHECK((lhs != rhs) == res);
    if ((lhs != rhs) != res) {
        std::cout << lhs << " == " << rhs << " = " << res << std::endl;
    }
}

TEST_CASE("[rational] - ctor") {
    test_input("26/13");
    test_input("13/3");
    test_input("-1/4");
    test_input("-1/1");
    test_input("-1/2");

    test_add(Rational(1, 2), Rational(1, 2), Rational(1, 1));
    test_add(Rational(1, 2), Rational(3, 1), Rational(7, 2));
    test_add(Rational(10, 1), Rational(-1, 2), Rational(19, 2));

    test_sub(Rational(1, 2), Rational(1, 2), Rational(0));
    test_sub(Rational(1, 2), Rational(2), Rational(-3, 2));
    test_sub(Rational(0), Rational(1, 2), Rational(-1, 2));

    test_mul(Rational(1, 2), Rational(1, 3), Rational(1, 6));
    test_mul(Rational(99, 100), Rational(0, 1), Rational(0));
    test_mul(Rational(-2), Rational(1, 2), Rational(-1));

    test_div(Rational(1, 2), Rational(1, 2), Rational(1));
    test_div(Rational(1, 2), Rational(1, 3), Rational(3, 2));
    test_div(Rational(0), Rational(99, 100), Rational(0));

    test_bigger(Rational(1, 2), Rational(1, 2), false);
    test_bigger(Rational(99, 100), Rational(1, 2), true);

    test_e_bigger(Rational(1, 2), Rational(1, 2), true);
    test_e_bigger(Rational(2), Rational(1, 2), true);

    test_smoller(Rational(1, 2), Rational(1, 2), false);
    test_smoller(Rational(4), Rational(100, 2), true);

    test_e_smoller(Rational(1, 2), Rational(1, 2), true);
    test_e_smoller(Rational(0), Rational(-1, 2), false);

    test_eq(Rational(10, 2), Rational(5), true);
    test_eq(Rational(99, 100), Rational(-99, 100), false);

    test_not_eq(Rational(1, 2), Rational(1, 2), false);
    test_not_eq(Rational(99, 100), Rational(9), true);
}