#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

void test_input(const std::string& inp) {
    std::istringstream istrm(inp);

    Rational t;
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

void test_bigger(const auto& lhs, const auto& rhs, const bool& res) {
    CHECK((lhs > rhs) == res);
    if ((lhs > rhs) != res) {
        std::cout << lhs << " > " << rhs << " -> " << res << std::endl;
    }
}

void test_e_bigger(const auto& lhs, const auto& rhs, const bool& res) {
    CHECK((lhs >= rhs) == res);
    if ((lhs >= rhs) != res) {
        std::cout << lhs << " >= " << rhs << " -> " << res << std::endl;
    }
}

void test_smoller(const auto& lhs, const auto& rhs, const bool& res) {
    CHECK((lhs < rhs) == res);
    if ((lhs < rhs) != res) {
        std::cout << lhs << " < " << rhs << " -> " << res << std::endl;
    }
}

void test_e_smoller(const auto& lhs, const auto& rhs, const bool& res) {
    CHECK((lhs <= rhs) == res);
    if ((lhs <= rhs) != res) {
        std::cout << lhs << " <= " << rhs << " -> " << res << std::endl;
    }
}

void test_eq(const auto& lhs, const auto& rhs, const bool& res) {
    CHECK((lhs == rhs) == res);
    if ((lhs == rhs) != res) {
        std::cout << lhs << " == " << rhs << " -> " << res << std::endl;
    }
}

void test_not_eq(const auto& lhs, const auto& rhs, const bool& res) {
    CHECK((lhs != rhs) == res);
    if ((lhs != rhs) != res) {
        std::cout << lhs << " == " << rhs << " = " << res << std::endl;
    }
}

TEST_CASE("[rational] - ctor") {
    test_input("26/13");
    test_input("13/3");
    test_input("-1 / 4");
    test_input("-1 / -1");

    test_add(Rational(1, 2), Rational(1, 2), 1);
    test_add(Rational(1, 2), 3, Rational(7, 2));
    test_add(10, Rational(-1, 2), Rational(19, 2));

    test_sub(Rational(1, 2), Rational(1, 2), 0);
    test_sub(Rational(1, 2), 2, Rational(-3, 2));
    test_sub(0, Rational(1, 2), Rational(-1, 2));

    test_mul(Rational(1, 2), Rational(1, 3), Rational(1, 6));
    test_mul(Rational(99, 100), 0, 0);
    test_mul(-2, Rational(1, 2), -1);

    test_div(Rational(1, 2), Rational(1, 2), 1);
    test_div(Rational(1, 2), Rational(1, 3), Rational(3, 2));
    test_div(0, Rational(99, 100), 0);

    test_bigger(Rational(1, 2), Rational(1, 2), false);
    test_bigger(Rational(99, 100), Rational(1, 2), true);

    test_e_bigger(Rational(1, 2), Rational(1, 2), true);
    test_e_bigger(2, Rational(1, 2), true);

    test_smoller(Rational(1, 2), Rational(1, 2), false);
    test_smoller(4, Rational(100, 2), true);

    test_e_smoller(Rational(1, 2), Rational(1, 2), true);
    test_e_smoller(0, Rational(-1, 2), false);

    test_eq(Rational(10, 2), 5, true);
    test_eq(Rational(99, 100), Rational(-99, 100), false);

    test_not_eq(Rational(1, 2), Rational(1, 2), false);
    test_not_eq(Rational(99, 100), 99, true);
}