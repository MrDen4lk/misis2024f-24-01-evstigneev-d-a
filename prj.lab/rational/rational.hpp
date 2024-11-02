#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <numeric>

// функция приведения числителя/знаменателя к несократимой дроби
inline long long update(long long numerator, long long denominator, bool type) {
    long long gcd_of_numbers = std::gcd(std::abs(numerator), std::abs(denominator));
    numerator = (((numerator < 0ll) + (denominator < 0ll)) == 1 ? -std::abs(numerator) : std::abs(numerator)) / gcd_of_numbers;
    denominator = std::abs(denominator) / gcd_of_numbers;
    if (type) {
        return numerator;
    }
    return denominator;
}

struct Rational {
    Rational() = default; // умолчательнывй конструктор 

    explicit Rational(const long long numerator) : num(numerator) {} // конструктор от 1 аргумента
    Rational(const long long numerator, const long long denominator) // конструктор от 2 аргументов
    : num(update(numerator, denominator, true)), den(update(numerator, denominator, false)) {}

    long long num{0ll}; // значение числителя
    long long den{1ll}; // значение знаменателя

    static const char left_point{'{'}; // левая граница записи рационального числа
    static const char mid_point{'/'}; // разделение числителя и знаменателя
    static const char right_point{'}'}; // кправая граница записи рационального числа

    Rational(const Rational&) = default;
    Rational(Rational&&) = default;

    // деструктор
    ~Rational() = default;

    // унарный минус
    Rational operator-() const noexcept;

    // присваивание
    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    // сложение с целым числом с присвоением
    Rational& operator+=(const long long rhs) noexcept;

    // сложение с рациональным числом с присвоением
    Rational& operator+=(const Rational& rhs) noexcept;

    // вычитание целого числа с присвеонием
    Rational& operator-=(const long long rhs) noexcept;
    
    // вычитание рационального числа с присвоением
    Rational& operator-=(const Rational& rhs) noexcept;

    // умножение на целое числа с присвеонием
    Rational& operator*=(const long long rhs) noexcept;

    // умножение на рациональное число с присвоением
    Rational& operator*=(const Rational& rhs) noexcept;

    // деление на целое число с присвоением
    Rational& operator/=(const long long rhs);

    // деление на рациональное число с присвоением
    Rational& operator/=(const Rational& rhs);

    // Форматированный вывод в поток outstream рационального числа числа в виде {num/den}
    std::ostream& write(std::ostream& outstream) const noexcept;

    // Форматированный ввод в поток instream рационального числа в виде {num/den}
    std::istream& read(std::istream& instream) noexcept;
};

// сложение рационального числа и рационального числа
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;

// сложение целого числа и рационального числа
Rational operator+(const long long lhs, const Rational& rhs) noexcept;

// сложение рационального числа и целого числа
Rational operator+(const Rational& lhs, const long long rhs) noexcept;

// вычитание рационального числа из рационального числа
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;

// вычитание целого числа из рационального числа
Rational operator-(const Rational& lhs, const long long rhs) noexcept;

// вычитание рационального числа из целого числа
Rational operator-(const long long lhs, const Rational& rhs) noexcept;

// умножение рационального числа на рациональное число
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;

// умножение рационального числа на целое число
Rational operator*(const Rational& lhs, const long long rhs) noexcept;

// умножение целого числа на рациональное число
Rational operator*(const long long lhs, const Rational& rhs) noexcept;

// деление рационального числа на рациональное число
Rational operator/(const Rational& lhs, const Rational& rhs);

// деление рационального числа на целое число
Rational operator/(const Rational& lhs, const long long rhs);

// деление целого числа на рациональное число
Rational operator/(const long long lhs, const Rational& rhs);

// операция больше для рационального числа и рационального числа
bool operator>(const Rational& lhs, const Rational& rhs) noexcept;

// операция больше для рационального и целого числа
bool operator>(const Rational& lhs, const long long rhs) noexcept;

// операция больше для целого и рационального числа
bool operator>(const long long lhs, const Rational& rhs) noexcept;

// оперция не меньше для рационального числа и рационального числа
bool operator>=(const Rational& lhs, const Rational& rhs) noexcept;

// оперция не меньше для рационального числа и целого числа
bool operator>=(const Rational& lhs, const long long rhs) noexcept;

// оперция не меньше для целого числа и рационального числа
bool operator>=(const long long lhs, const Rational& rhs) noexcept;

// оперция меньше для рационального числа и рационального числа
bool operator<(const Rational& lhs, const Rational& rhs) noexcept;

// оперция меньше для рационального числа и целого числа
bool operator<(const Rational& lhs, const long long rhs) noexcept;

// оперция меньше для целого числа и рационального числа
bool operator<(const long long lhs, const Rational& rhs) noexcept;

// оперция не больше для рационального числа и рационального числа
bool operator<=(const Rational& lhs, const Rational& rhs) noexcept;

// оперция не больше для рационального числа и целого числа
bool operator<=(const Rational& lhs, const long long rhs) noexcept;

// оперция не больше для целого числа и рационального числа
bool operator<=(const long long lhs, const Rational& rhs) noexcept;

// операция сравнения на равенство рационального числа и рационального числа
bool operator==(const Rational& lhs, const Rational& rhs) noexcept;

// операция сравнения на равенство рационального числа и целого числа
bool operator==(const Rational& lhs, const long long rhs) noexcept;

// операция сравнения на равенство целого числа и рационального числа
bool operator==(const long long lhs, const Rational& rhs) noexcept;

// операция сравнения на неравенство рационального числа и рационального числа
bool operator!=(const Rational& lhs, const Rational& rhs) noexcept;

// операция сравнения на неравенство рационального числа и целого числа
bool operator!=(const Rational& lhs, const long long rhs) noexcept;

// операция сравнения на неравенство целого числа и рационального числа
bool operator!=(const long long lhs, const Rational& rhs) noexcept;

// форматированный вывод в поток outstream рационального числа
inline std::ostream& operator<<(std::ostream& outstream, const Rational& rhs) noexcept { return rhs.write(outstream); }

// Форматированный ввод из потока instream рационального числа
inline std::istream& operator>>(std::istream& instream, Rational& rhs) noexcept { return rhs.read(instream); }

#endif