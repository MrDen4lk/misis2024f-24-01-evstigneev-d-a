#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iosfwd>

// структура для хранения и действий с комплексными числами
struct Complex {
    Complex() = default; // умолчательный констурктор

    // копирующий конструктор
    Complex(const Complex&) = default;
    Complex(Complex&&) = default;

    explicit Complex(const double real) : re(real) {} // констурктор от 1 аргумента без неявного вызова 
    Complex(const double real, const double imaginary) : re(real), im(imaginary) {} // конструктор от 2 аргументов
    
    double re{ 0.0 }; // значение реальной части комплексного числа
    double im{ 0.0 }; // значение мнимой части комлпекласного числа
    
    static const char left_point{ '{' }; // левая граница записи комплексного числа
    static const char right_point{ '}' }; // правая граница записи комплексного числа
    static const char mid_point{ ',' }; // разделитель реальной и мнимой части при записи комплекасного числа


    // присваивание
    Complex& operator=(const Complex&) = default;
    Complex& operator=(Complex&&) = default;

    // деструктор
    ~Complex() = default;
        
    // унарный минус
    Complex operator-() const noexcept;

    // присваивающее сложение с комплексным числом
    Complex& operator+=(const Complex& rhs) noexcept;
    
    // присваивающее сложение с вещественным числом
    Complex& operator+=(const double rhs) noexcept;

    // присваивающее вычитание комплексного числа
    Complex& operator-=(const Complex& rhs) noexcept;

    // присваивающее вычитание вещественного числа
    Complex& operator-=(const double rhs) noexcept;

    // присваивающее умножение на комплексное число
    Complex& operator*=(const Complex& rhs) noexcept;

    // присваивающее умножение на вещественное число
    Complex& operator*=(const double rhs) noexcept;

    // присваивающее деление на комплексное число
    Complex& operator/=(const Complex& rhs);

    // присваивающее деление на вещевстенное число 
    Complex& operator/=(const double rhs);
    
    // Форматированный вывод в поток outstream комплексного числа в виде {re,im}
    std::ostream& write(std::ostream& outstream) const noexcept;

    // Форматированный ввод в поток instream комплексного числа в виде {re,im}
    std::istream& read(std::istream& instream) noexcept;
};

// сравние комплексного числа и комплексного числа
bool operator==(const Complex& lhs, const Complex& rhs) noexcept;
bool operator!=(const Complex& lhs, const Complex& rhs) noexcept;

// сложениe комплексного числа и комплексного числа
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;

// сложение комплексного числа и вещественного числа
Complex operator+(const Complex& lhs, const double rhs) noexcept;

// сложение вещественного числа и комплексного числа
Complex operator+(const double lhs, const Complex& rhs) noexcept;

// вычитание комплексного числа из комплексного числа
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;

// вычитание вещественного числа из комплексного числа
Complex operator-(const Complex& lhs, const double rhs) noexcept;

// вычитание комплексного числа из вещественного числа
Complex operator-(const double lhs, const Complex& rhs) noexcept;

// умножение комплексного числа на вещественное число 
Complex operator*(const Complex& lhs, const double rhs) noexcept;

// умножение вещественного числа на комплексное число
Complex operator*(const double lhs, const Complex& rhs) noexcept;

// умножение комплексного числа на комплексное число
Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;

// деление комплексного числа на вещественное число
Complex operator/(const Complex& lhs, const double rhs);

// деление комплексного числа на комплексное число
Complex operator/(const Complex& lhs, const Complex& rhs);

// форматированный вывод в поток outstream комплексного числа
inline std::ostream& operator<<(std::ostream& outstream, const Complex& rhs) noexcept { return rhs.write(outstream); }

// Форматированный ввод из потока instream комплексного числа
inline std::istream& operator>>(std::istream& instream, Complex& rhs) noexcept { return rhs.read(instream); }

#endif
