#include <iostream>
#include <sstream>

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

// конструктор для 1 агрумента
Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

// конструктов для 2 агрументов
Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

// реализация метода структры для вывода компеклсного числа 
std::ostream& Complex::write(std::ostream& outstream) const {
    return outstream << left_point << re << mid_point << im << right_point;
}

// реализация метода структуры для ввода комплексного числа
std::istream& Complex::read(std::istream& instream) {
    double real(0.0);
    double imaginary(0.0);
    char left_point(0);
    char right_point(0);
    char mid_point(0);
    instream >> left_point >> real >> mid_point >> imaginary >> right_point;
    if (instream.good()) {
        if ((mid_point == Complex::mid_point) && (left_point == Complex::left_point) && (right_point == Complex::right_point)) {
            re = real;
            im = imaginary;
        } else {
            instream.setstate(std::ios_base::failbit);
        }
    }
    return instream;
}

// реализация сложения 2 комплексных чисел
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(rhs.re + lhs.re, rhs.im + lhs.im);
}

// реализация сложения действительного числа с комплексным числом
Complex operator+(const double lhs, const Complex& rhs) {
    return Complex(rhs.re + lhs, rhs.im);
}

// реализация сложения комплексного числа с действительным числом
Complex operator+(const Complex& lhs, const double rhs) {
    return Complex(lhs.re + rhs, lhs.im);
}

// реализация вычитания 2 комлексных чисел
Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

// реализация вычитания действительного числа из комплексного
Complex operator-(const Complex& lhs, const double rhs) {
    return Complex(lhs.re - rhs, lhs.im);
}

// реализация умножение комплексного числа на действительное число
Complex operator*(const Complex& lhs, const double rhs) {
    return Complex(lhs.re * rhs, lhs.im * rhs);
}

// реализация умножения действительного числа на комплексное число
Complex operator*(const double lhs, const Complex& rhs) {
    return Complex(lhs * rhs.re, lhs * rhs.im);
}

// реализация умножения 2 комплексных чисел
Complex operator*(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + lhs.im * rhs.re);
}

// реализация деления 2 комплексных чисел
Complex operator/(const Complex& lhs, const Complex& rhs) {
    double re = (lhs.re * lhs.im + rhs.re * rhs.im) / (lhs.im * lhs.im + rhs.im * rhs.im);
    double im = (lhs.im * rhs.re - lhs.re * rhs.im) / (lhs.im * lhs.im + rhs.im * rhs.im);
    return Complex(re, im);
}

// реализация деления компелксного числа на действительное число
Complex operator/(const Complex& lhs, const double rhs) {
    return Complex(lhs.re / rhs, lhs.im / rhs);
}

// реализация метода структуры для сложения с комплексным числом с присвоением
Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this; 
}

// реализация метода структуры для сложения с комплексным числом с присвоением
Complex& Complex::operator+=(const double rhs) {
    re += rhs;
    return *this; 
}

// реализация метода структуры для вычитания компелксного числа с присвоением
Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

// реализация метода структуры для вычитания компелксного числа с присвоением
Complex& Complex::operator-=(const double rhs) {
    re -= rhs;
    return *this;
}

// реализация метода структуры для умножение на компеклсное число с присвоением
Complex& Complex::operator*=(const Complex& rhs) {
    double new_re = re = re * rhs.re - im * rhs.im;
    double new_im = re * rhs.im + im * rhs.re;
    re = new_re;
    im = new_im;
    return *this;
}

// реализация метода структуры для умножения на действительное число с присвоением
Complex& Complex::operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;
    return *this;
}

// реализация метода структуры для деления на компелксное число с присвоением
Complex& Complex::operator/=(const Complex& rhs) {
    double new_re = (re * im + rhs.re * rhs.im) / (im * im + rhs.im * rhs.im);
    double new_im = (im * rhs.re - re * rhs.im) / (im * im + rhs.im * rhs.im);
    re = new_re;
    im = new_im;
    return *this;
}

// реализация метода структуры для деления на действительное число с присвоением
Complex& Complex::operator/=(const double rhs) {
    re /= rhs;
    im /= rhs;
    return *this;
}

// функция тестирование работоспособности структуры
bool test_modul(const std::string& str) {
    Complex z;

    std::istringstream instream(str);
    instream >> z;
    z += 2;
    std::cout << z << std::endl;
    std::cout << Complex(5, 0) * 6 << std::endl;
    z *= Complex(5, 7);
    std::cout << z << std::endl;
    
    return instream.good();
}

int main() {
    
    test_modul("{2,3}");
    std::cout << (Complex(-2, 1) / Complex(1, -1));

    return 0;
}
