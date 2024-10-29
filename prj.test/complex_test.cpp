#include <complex/complex.hpp>
#include <iostream>
#include <sstream>

// тестирование ввода
bool test_input(const std::string& inp) {
    std::istringstream istrm(inp);

    Complex t;
    istrm >> t;

    if (istrm.good()) {
        std::cout << "Success: " << inp << " -> " << t << std::endl;
    } else {
        std::cout << "Error: " << inp << " -> " << t << std::endl;
    }

    return istrm.good();
}

// тестирование арифметических операций и операций сравнения
void test_arithmetics(const Complex& a = {1., 1.}, const Complex& b = {1., 1.}, const double c = 1.) {
    static int number_of_test = 0;
    number_of_test++;
    const std::string separator = "============================================================";
    Complex extra_a_complex;
    Complex extra_a_double;

    std::cout << std::endl << "===========================Test#" << number_of_test << "===========================" << std::endl;
    std::cout << "Frist complex number: " << a << std::endl;
    std::cout << "Second complex number: " << b << std::endl;
    std::cout << "Third double number: " << c << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций сложения
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " + " << c << " = " << a + c << std::endl;
    std::cout << c << " + " << b << " = " << c + b << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций сложения с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex += b;
    extra_a_double += c;

    std::cout << a << " += " << b << " | " << a << " -> " << extra_a_complex << std::endl;
    std::cout << a << " += " << c << " | " << a << " -> " << extra_a_double << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций вычитания
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " - " << c << " = " << a - c << std::endl;
    std::cout << c << " - " << b << " = " << c - b << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций вычитания с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex -= b;
    extra_a_double -= c;

    std::cout << a << " -= " << b << " | " << a << " -> " << extra_a_complex << std::endl;
    std::cout << a << " -= " << c << " | " << a << " -> " << extra_a_double << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций умножения
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " * " << c << " = " << a * c << std::endl;
    std::cout << c << " * " << b << " = " << c * b << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций умножения с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex *= b;
    extra_a_double *= c;

    std::cout << a << " *= " << b << " | " << a << " -> " << extra_a_complex << std::endl;
    std::cout << a << " *= " << c << " | " << a << " -> " << extra_a_double << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций деления
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " / " << c << " = " << a / c << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций деления с присвоением
    extra_a_complex = a;
    extra_a_double = a;
    extra_a_complex /= b;
    extra_a_double /= c;

    std::cout << a << " /= " << b << " | " << a << " -> " << extra_a_complex << std::endl;
    std::cout << a << " /= " << c << " | " << a << " -> " << extra_a_double << std::endl;
    std::cout << separator << std::endl;

    // тестирование операций сравнение
    std::cout << a << " == " << b << " -> " << (a == b) << std::endl;
    std::cout << a << " != " << b << " -> " << (a != b) << std::endl;
    std::cout << a << " == " << (b + c) << " -> " << (a == (b + c)) << std::endl;
    std::cout << a << " != " << (b + c) << " -> " << (a != (b + c)) << std::endl;
    std::cout << "===========================End#" << number_of_test << "============================" << std::endl;
}

int main() {
    test_input("{1, 1}");
    test_input("{1,1}");
    test_input("{1.1}");
    test_input("{1,1");
    test_input("1.1}");

    test_arithmetics({1, 2}, {3, 4}, 1);
    test_arithmetics({-2, 4}, {-1, -5}, 5);
    test_arithmetics({7, 7}, {7, 7}, -5);
}
