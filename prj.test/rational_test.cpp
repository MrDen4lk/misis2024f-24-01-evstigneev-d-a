#include <rational/rational.hpp>
#include <sstream>
#include <iostream>

// тестирование ввода
bool test_input(const std::string& inp) {
    static int number_of_test = 0;
    number_of_test++;
    std::cout << "Test#" << number_of_test << std::endl;

    std::istringstream istrm{inp};
    Rational a;
    istrm >> a;
    if (istrm.good()) {
        std::cout << "Success: " << inp << " -> " << a << std::endl;
    } else {
        std::cout << "Failed: " << inp << " -> " << a << std::endl;
    }

    return istrm.good();
}

// тестирование арифметических операций
void test_arithmetics(const Rational& a = {1, 1}, const Rational& b = {1, 1}, const int64_t c = 1ll) {
    static int number_of_test = 0;
    number_of_test++;

    std::cout << std::endl << "===========================Test#" << number_of_test << "===========================" << std::endl;
    std::cout << "First number: " << a << std::endl;
    std::cout << "Second number: " << b << std::endl;
    std::cout << "Third number: " << c << std::endl;
    std::cout << std::endl;

    Rational extra_a_rational;
    Rational extra_a_long;

    // тестирование операций сложения
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " + " << c << " = " << a + c << std::endl;
    std::cout << c << " + " << b << " = " << c + b << std::endl;
    std::cout << std::endl;

    // тестирование операций сложения с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational += b;
    extra_a_long += c;

    std::cout << a << " += " << b << " | " << a << " -> " << extra_a_rational << std::endl;
    std::cout << a << " += " << c << " | " << a << " -> " << extra_a_long << std::endl;
    std::cout << std::endl;

    // тестирование операций вычитания
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " - " << c << " = " << a - c << std::endl;
    std::cout << c << " - " << b << " = " << c - b << std::endl;
    std::cout << std::endl;

    // тестирование операций вычитания с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational -= b;
    extra_a_long -= c;

    std::cout << a << " -= " << b << " | " << a << " -> " << extra_a_rational << std::endl;
    std::cout << a << " -= " << c << " | " << a << " -> " << extra_a_long << std::endl;
    std::cout << std::endl;

    // тестирование операций умножения
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " * " << c << " = " << a * c << std::endl;
    std::cout << c << " * " << b << " = " << c * b << std::endl;
    std::cout << std::endl;

    // тестирование операций умножения с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational *= b;
    extra_a_long *= c;

    std::cout << a  << " *= " << b << " | " << a << " -> " << extra_a_rational << std::endl;
    std::cout << a << " *= " << c << " | " << a << " -> " << extra_a_long << std::endl;
    std::cout << std::endl;

    // тестирование операций деления
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " / " << c << " = " << a / c << std::endl;
    std::cout << c << " / " << b << " = " << c / b << std::endl;
    std::cout << std::endl;

    // тестирование операций деления с присвоением
    extra_a_rational = a;
    extra_a_long = a;
    extra_a_rational /= b;
    extra_a_long /= c;

    std::cout << a << " /= " << b << " | " << a << " -> " << extra_a_rational << std::endl;
    std::cout << a << " / " << c << " | " << a << " -> " << extra_a_long << std::endl;

    std::cout << "===========================End#" << number_of_test << "============================" << std::endl;
}

// тестирование логических операций
void test_logic(const Rational& a = {1, 1}, const Rational& b = {1, 1}, const int64_t c = 1ll) {
    static int number_of_test = 0;
    number_of_test++;

    std::cout << std::endl << "===========================Test#" << number_of_test << "===========================" << std::endl;
    std::cout << "First number: " << a << std::endl;
    std::cout << "Second number: " << b << std::endl;
    std::cout << "Third number: " << c << std::endl;
    std::cout << std::endl;

    // тестирование операций >
    std::cout << a << " > " << b << " -> " << (a > b ? "true" : "false") << std::endl;
    std::cout << a << " > " << c << " -> " << (a > c ? "true" : "false") << std::endl;
    std::cout << c << " > " << b << " -> " << (c > b ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // тестирование операций >=
    std::cout << a << " >= " << b << " -> " << (a >= b ? "true" : "false") << std::endl;
    std::cout << a << " >= " << c << " -> " << (a >= c ? "true" : "false") << std::endl;
    std::cout << c << " >= " << b << " -> " << (c >= b ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // тестирование операций <
    std::cout << a << " < " << b << " -> " << (a < b ? "true" : "false") << std::endl;
    std::cout << a << " < " << c << " -> " << (a < c ? "true" : "false") << std::endl;
    std::cout << c << " < " << b << " -> " << (c < b ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // тестирование операций <=
    std::cout << a << " <= " << b << " -> " << (a <= b ? "true" : "false") << std::endl;
    std::cout << a << " <= " << c << " -> " << (a <= c ? "true" : "false") << std::endl;
    std::cout << c << " <= " << b << " -> " << (c <= b ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // тестирование операций ==
    std::cout << a << " == " << b << " -> " << (a == b ? "true" : "false") << std::endl;
    std::cout << a << " == " << c << " -> " << (a == c ? "true" : "false") << std::endl;
    std::cout << c << " == " << b << " -> " << (c == b ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // тестирование операций !=
    std::cout << a << " != " << b << " -> " << (a != b ? "true" : "false") << std::endl;
    std::cout << a << " != " << c << " -> " << (a != c ? "true" : "false") << std::endl;
    std::cout << c << " != " << b << " -> " << (c != b ? "true" : "false") << std::endl;

    std::cout << "===========================End#" << number_of_test << "============================" << std::endl;
}

int main() {
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

    return 0;
}