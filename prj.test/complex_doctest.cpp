#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::string get_string_of_complex(const Complex& a) {
    return ("{" + std::to_string(a.re) + "," + std::to_string(a.im) + "}");
}

// тестирование ввода
void test_input(const std::string& inp) {
    std::istringstream istrm(inp);

    Complex t;
    istrm >> t;

    if (istrm.good()) {
        CHECK_MESSAGE(istrm.good(), inp);
    } else {
        CHECK_FALSE_MESSAGE(istrm.good(), inp);
    }
}

void test_arithmetics(const Complex& a = {1., 1.}, const Complex& b = {1., 1.}, const double c = 1.) {
    Complex extra_a_complex = {};
    Complex extra_a_double = {};
    std::string message = "";

    // тестирование операций сложения
    extra_a_complex = a + b;
    message = get_string_of_complex(a) + " + " + get_string_of_complex(b) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re + b.re, a.im + b.im), message);
    extra_a_complex = a + c;
    message = get_string_of_complex(a) + " + " + std::to_string(c) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re + c, a.im), message);
    extra_a_complex = c + b;
    message = std::to_string(c) + " + " + get_string_of_complex(b) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(c + b.re, b.im), message);

    // тестирование операций сложения с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex += b;
    extra_a_double += c;

    message = get_string_of_complex(a) + " += " + get_string_of_complex(b) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re + b.re, a.im + b.im), message);
    message = get_string_of_complex(a) + " += " + std::to_string(c) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_double);
    CHECK_MESSAGE(extra_a_double == Complex(a.re + c, a.im ), message);

    // тестирование операций вычитания
    extra_a_complex = a - b;
    message = get_string_of_complex(a) + " - " + get_string_of_complex(b) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re - b.re, a.im - b.im), message);
    extra_a_complex = a - c;
    message = get_string_of_complex(a) + " - " + std::to_string(c) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re - c, a.im), message);
    extra_a_complex = c - b;
    message = std::to_string(c) + " - " + get_string_of_complex(b) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(c - b.re, -b.im), message);

    // тестирование операций вычитания с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex -= b;
    extra_a_double -= c;

    message = get_string_of_complex(a) + " -= " + get_string_of_complex(b) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re - b.re, a.im - b.im), message);
    message = get_string_of_complex(a) + " -= " + std::to_string(c) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_double);
    CHECK_MESSAGE(extra_a_double == Complex(a.re - c, a.im ), message);

    // тестирование операций умножения
    extra_a_complex = a * b;
    message = get_string_of_complex(a) + " * " + get_string_of_complex(b) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re), message);
    extra_a_complex = a * c;
    message = get_string_of_complex(a) + " * " + std::to_string(c) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re * c, a.im * c), message);
    extra_a_complex = c * b;
    message = std::to_string(c) + " * " + get_string_of_complex(b) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(c * b.re, b.im * c), message);

    // тестирование операций умножения с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex *= b;
    extra_a_double *= c;

    message = get_string_of_complex(a) + " *= " + get_string_of_complex(b) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re), message);
    message = get_string_of_complex(a) + " *= " + std::to_string(c) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_double);
    CHECK_MESSAGE(extra_a_double == Complex(a.re * c, a.im * c), message);

    // тестирование операций деления
    extra_a_complex = a / b;
    message = get_string_of_complex(a) + " / " + get_string_of_complex(b) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex((a.re * a.im + b.re * b.im) / (a.im * a.im + b.im * b.im), (a.im * b.re - a.re * b.im) / (a.im * a.im + b.im * b.im)), message);
    extra_a_complex = a / c;
    message = get_string_of_complex(a) + " / " + std::to_string(c) + " = " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex(a.re / c, a.im / c), message);

    // тестирование операций деления с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex /= b;
    extra_a_double /= c;

    message = get_string_of_complex(a) + " /= " + get_string_of_complex(b) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_complex);
    CHECK_MESSAGE(extra_a_complex == Complex((a.re * a.im + b.re * b.im) / (a.im * a.im + b.im * b.im), (a.im * b.re - a.re * b.im) / (a.im * a.im + b.im * b.im)), message);
    message = get_string_of_complex(a) + " /= " + std::to_string(c) + " | " + get_string_of_complex(a) + " -> " + get_string_of_complex(extra_a_double);
    CHECK_MESSAGE(extra_a_double == Complex(a.re / c, a.im / c), message);
}

void test_logic(const Complex& a = {1., 1.}, const Complex& b = {1., 1.}, const double c = 1.) {
    std::string message = "";

    // тестирование операций сравнение
    message = get_string_of_complex(a) + " == " + get_string_of_complex(b) + " -> " + std::to_string(a == b);
    if (a.im == b.im && a.re == b.re) {
        CHECK_MESSAGE(a == b, message);
    } else {
        CHECK_FALSE_MESSAGE(a == b, message);
    }
    message = get_string_of_complex(a) + " != " + get_string_of_complex(b) + " -> " + std::to_string(a != b);
    if (a.im != b.im || a.re != b.re) {
        CHECK_MESSAGE(a != b, message);
    } else {
        CHECK_FALSE_MESSAGE(a != b, message);
    }
    message = get_string_of_complex(a) + " == " + get_string_of_complex(b + c) + " -> " + std::to_string(a == (b + c));
    if (a.im == b.im && a.re == (b.re + c)) {
        CHECK_MESSAGE(a == (b + c), message);
    } else {
        CHECK_FALSE_MESSAGE(a == (b + c), message);
    }
    message = get_string_of_complex(a) + " != " + get_string_of_complex(b + c) + " -> " + std::to_string(a != (b + c));
    if (a.im != b.im || a.re != (b.re + c)) {
        CHECK_MESSAGE(a != (b + c), message);
    } else {
        CHECK_FALSE_MESSAGE(a != (b + c), message);
    }
}

TEST_CASE("[complex] - ctor") {
    test_input("{1, 1}");
    test_input("{1,1}");
    test_input("{1.1}");
    test_input("{1,1");
    test_input("1.1}");

    test_arithmetics({1, 2}, {3, 4}, 1);
    test_arithmetics({-2, 4}, {-1, -5}, 5);
    test_arithmetics({7, 7}, {7, 7}, -5);

    test_logic({1, 2}, {3, 4}, 1);
    test_logic({-2, 4}, {-1, -5}, 5);
    test_logic({7, 7}, {7, 7}, -5);
}