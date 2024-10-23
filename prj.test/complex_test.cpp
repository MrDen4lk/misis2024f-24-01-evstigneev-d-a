#include <complex/complex.hpp>
#include <iostream>

int main() {
    Complex a(10, 20);
    Complex b(-9, 11);
    double c{3.0};

    std::cout << "============================" << std::endl;
    std::cout << "Frist complex number: " << a << std::endl;
    std::cout << "Second complex number: " << b << std::endl;
    std::cout << "Third double number: " << c << std::endl;
    std::cout << "============================" << std::endl;


    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " + " << c << " = " << a + c << std::endl;
    std::cout << c << " + " << b << " = " << c + b << std::endl;

    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " - " << c << " = " << a - c << std::endl;

    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " * " << c << " = " << a * c << std::endl;
    std::cout << c << " * " << b << " = " << c * b << std::endl;

    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " / " << c << " = " << a / c << std::endl;
}
