#ifndef COMPLEX_HPP
#define COMPLEX_HPP

// структура для хранения и действий с комплексными числами
struct Complex {
    Complex() {}; //констуктор от 0 аргументов
    explicit Complex(const double real); // объявление констурктора от 1 аргумента без неявного вызова 
    Complex(const double real, const double imaginary); // объявление конструктора от 2 аргументов
    
    double re{ 0.0 }; // значение реальной части комплексного числа
    double im{ 0.0 }; // значение мнимой части комлпекласного числа
    static const char left_point{ '{' }; // левая граница записи комплексного числа
    static const char right_point{ '}' }; // правая граница записи комплексного числа
    static const char mid_point{ ',' }; // разделитель реальной и мнимой части при записи комплекасного числа

    // реализация логических операций для комплексных чисел
    bool operator==(const Complex& rhs) { return ((rhs.re == re) && (rhs.im == im)); };
    bool operator!=(const Complex& rhs) { return !operator==(rhs); };
        
    // объявление методов структуры для реализация дейсвтвий с комплексными числами, итог которого записывается в объект, с которым исполняется действие
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);
    
    // объявление метода структуры для ввода и вывода комплексных чисел
    std::ostream& write(std::ostream& outstream) const;
    std::istream& read(std::istream& instream);
};

// объявление действий с комплекасными числами, итоге которого записывется в другой объект
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

// реализация ввода и вывода комплексных чисел
std::ostream& operator<<(std::ostream& outstream, const Complex& rhs) { return rhs.write(outstream); }
std::istream& operator>>(std::istream& instream, Complex& rhs) { return rhs.read(instream); }

#endif
