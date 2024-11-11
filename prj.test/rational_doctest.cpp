#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::string to_string(const Rational& a) {
    std::pair<int64_t, int64_t> data = Rational::data_for_testing(a);
    return std::to_string(data.first) + "/" + std::to_string(data.second);
}

// тестирование ввода
void test_input(const std::string& inp) {
    std::istringstream istrm{inp};
    Rational a;
    istrm >> a;

    if (istrm.good()) {
        CHECK_MESSAGE(istrm.good(), inp);
    } else {
        CHECK_FALSE_MESSAGE(istrm.good(), inp);
    }
}

// тестирование арифметических операций
void test_arithmetics(const Rational& a = {1, 1}, const Rational& b = {1, 1}, const int64_t c = 1ll) {
    Rational extra_a_rational = {};
    Rational extra_a_long = {};
    std::pair<int64_t, int64_t> value_a = Rational::data_for_testing(a);
    std::pair<int64_t, int64_t> value_b = Rational::data_for_testing(b);
    std::string message = "";

    // тестирование операций сложения
    extra_a_rational = a + b;
    message = to_string(a) + " + " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.second + value_a.second * value_b.first, value_a.second * value_b.second), message);
    extra_a_rational = a + c;
    message = to_string(a) + " + " + std::to_string(c) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first + c * value_a.second, value_a.second), message);
    extra_a_rational = c + b;
    message = std::to_string(c) + " + " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(c * value_b.second + value_b.first, value_b.second), message);

    // тестирование операций сложения с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational += b;
    extra_a_long += c;

    message = to_string(a) + " += " + to_string(b) + " | " + to_string(a) + " -> " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.second + value_a.second * value_b.first, value_a.second * value_b.second), message);
    message = to_string(a) + " += " + std::to_string(c) + " | " + to_string(a) + " -> " + to_string(extra_a_long);
    CHECK_MESSAGE(extra_a_long == Rational(value_a.first + c * value_a.second, value_a.second), message);

    // тестирование операций вычитания
    extra_a_rational = a - b;
    message = to_string(a) + " - " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.second - value_a.second * value_b.first, value_a.second * value_b.second), message);
    extra_a_rational = a - c;
    message = to_string(a) + " - " + std::to_string(c) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first - c * value_a.second, value_a.second), message);
    extra_a_rational = c - b;
    message = std::to_string(c) + " - " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(c * value_b.second - value_b.first, value_b.second), message);

    // тестирование операций вычитания с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational -= b;
    extra_a_long -= c;

    message = to_string(a) + " -= " + to_string(b) + " | " + to_string(a) + " -> " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.second - value_a.second * value_b.first, value_a.second * value_b.second), message);
    message = to_string(a) + " -= " + std::to_string(c) + " | " + to_string(a) + " -> " + to_string(extra_a_long);
    CHECK_MESSAGE(extra_a_long == Rational(value_a.first - c * value_a.second, value_a.second), message);

    // тестирование операций умножения
    extra_a_rational = a * b;
    message = to_string(a) + " * " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.first, value_a.second * value_b.second), message);
    extra_a_rational = a * c;
    message = to_string(a) + " * " + std::to_string(c) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * c, value_a.second), message);
    extra_a_rational = c * b;
    message = std::to_string(c) + " * " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(c * value_b.first, value_b.second), message);

    // тестирование операций умножения с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational *= b;
    extra_a_long *= c;

    message = to_string(a) + " *= " + to_string(b) + " | " + to_string(a) + " -> " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.first, value_a.second * value_b.second), message);
    message = to_string(a) + " *= " + std::to_string(c) + " | " + to_string(a) + " -> " + to_string(extra_a_long);
    CHECK_MESSAGE(extra_a_long == Rational(value_a.first * c, value_a.second), message);

    // тестирование операций деления
    extra_a_rational = a / b;
    message = to_string(a) + " / " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.second, value_a.second * value_b.first), message);
    extra_a_rational = a / c;
    message = to_string(a) + " / " +std::to_string(c) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first, value_a.second * c), message);
    extra_a_rational = c / b;
    message = std::to_string(c) + " / " + to_string(b) + " = " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(c * value_b.second, value_b.first), message);

    // тестирование операций деления с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational /= b;
    extra_a_long /= c;

    message = to_string(a) + " /= " + to_string(b) + " | " + to_string(a) + " -> " + to_string(extra_a_rational);
    CHECK_MESSAGE(extra_a_rational == Rational(value_a.first * value_b.second, value_a.second * value_b.first), message);
    message = to_string(a) + " /= " + std::to_string(c) + " | " + to_string(a) + " -> " + to_string(extra_a_long);
    CHECK_MESSAGE(extra_a_long == Rational(value_a.first, value_a.second * c), message);
}

// тестирование логических операций
void test_logic(const Rational& a = {1, 1}, const Rational& b = {1, 1}, const int64_t c = 1ll) {
    std::string message = "";
    std::pair<int64_t, int64_t> value_a = Rational::data_for_testing(a);
    std::pair<int64_t, int64_t> value_b = Rational::data_for_testing(b);

    // тестирование операций >
    message = to_string(a) + " > " + to_string(b) + " -> " + (a > b ? "true" : "false");
    CHECK_MESSAGE((a > b) == (value_a.first * value_b.second > value_a.second * value_b.first), message);
    message = to_string(a) + " > " + std::to_string(c) + " -> " + (a > c ? "true" : "false");
    CHECK_MESSAGE((a > c) == (value_a.first > value_a.second * c), message);
    message = std::to_string(c) + " > " + to_string(b) + " -> " + (c > b ? "true" : "false");
    CHECK_MESSAGE((c > b) == (c * value_b.second > value_b.first), message);

    // тестирование операций >=
    message = to_string(a) + " >= " + to_string(b) + " -> " + (a >= b ? "true" : "false");
    CHECK_MESSAGE((a >= b) == (value_a.first * value_b.second >= value_a.second * value_b.first), message);
    message = to_string(a) + " >= " + std::to_string(c) + " -> " + (a >= c ? "true" : "false");
    CHECK_MESSAGE((a >= c) == (value_a.first >= value_a.second * c), message);
    message = std::to_string(c) + " >= " + to_string(b) + " -> " + (c >= b ? "true" : "false");
    CHECK_MESSAGE((c >= b) == (c * value_b.second >= value_b.first), message);

    // тестирование операций <
    message = to_string(a) + " < " + to_string(b) + " -> " + (a < b ? "true" : "false");
    CHECK_MESSAGE((a < b) == (value_a.first * value_b.second < value_a.second * value_b.first), message);
    message = to_string(a) + " < " + std::to_string(c) + " -> " + (a < c ? "true" : "false");
    CHECK_MESSAGE((a < c) == (value_a.first < value_a.second * c), message);
    message = std::to_string(c) + " < " + to_string(b) + " -> " + (c < b ? "true" : "false");
    CHECK_MESSAGE((c < b) == (c * value_b.second < value_b.first), message);

    // тестирование операций <=
    message = to_string(a) + " <= " + to_string(b) + " -> " + (a <= b ? "true" : "false");
    CHECK_MESSAGE((a <= b) == (value_a.first * value_b.second <= value_a.second * value_b.first), message);
    message = to_string(a) + " <= " + std::to_string(c) + " -> " + (a <= c ? "true" : "false");
    CHECK_MESSAGE((a <= c) == (value_a.first <= value_a.second * c), message);
    message = std::to_string(c) + " <= " + to_string(b) + " -> " + (c <= b ? "true" : "false");
    CHECK_MESSAGE((c <= b) == (c * value_b.second <= value_b.first), message);

    // тестирование операций ==
    message = to_string(a) + " == " + to_string(b) + " -> " + (a == b ? "true" : "false");
    CHECK_MESSAGE((a == b) == (value_a.first * value_b.second == value_a.second * value_b.first), message);
    message = to_string(a) + " == " + std::to_string(c) + " -> " + (a == c ? "true" : "false");
    CHECK_MESSAGE((a == c) == (value_a.first == value_a.second * c), message);
    message = std::to_string(c) + " == " + to_string(b) + " -> " + (c == b ? "true" : "false");
    CHECK_MESSAGE((c == b) == (c * value_b.second == value_b.first), message);

    // тестирование операций !=
    message = to_string(a) + " != " + to_string(b) + " -> " + (a != b ? "true" : "false");
    CHECK_MESSAGE((a != b) == (value_a.first * value_b.second != value_a.second * value_b.first), message);
    message = to_string(a) + " > " + std::to_string(c) + " -> " + (a != c ? "true" : "false");
    CHECK_MESSAGE((a != c) == (value_a.first != value_a.second * c), message);
    message = std::to_string(c) + " > " + to_string(b) + " -> " + (c != b ? "true" : "false");
    CHECK_MESSAGE((c != b) == (c * value_b.second != value_b.first), message);
}

TEST_CASE("[rational] - ctor") {
    test_input("1/ 3");
    test_input("8/2");
    test_input("4.9");
    test_input("4/0");
    test_input("6,-50");

    test_arithmetics({1, 2}, {1, 3}, 5);
    test_arithmetics({5, 7}, {-4, 16}, -2);
    test_arithmetics({10, 1}, {-2, 6}, 7);

    test_logic({1, 2}, {1, 3}, 1);
    test_logic({1, -2}, {-2, 4}, 2);
    test_logic({10, 1}, {-5, -2}, 10);
}