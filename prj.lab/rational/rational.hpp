#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>
#include <cstdint>
#include <stdexcept>

class Rational {
private:
    std::int64_t num_{0}; // значение числителя
    std::int64_t den_{1}; // значение знаменателя

    static const char mid_point{'/'}; // разделение числителя и знаменателя

    // функция приведения числителя/знаменателя к несократимой дроби
    void update(const std::int64_t numerator, const std::int64_t denominator);

public:
    Rational() = default; // умолчательный конструктор

    explicit Rational(const std::int64_t numerator) : num_(numerator) {} // конструктор от 1 аргумента
    Rational(const std::int64_t numerator, const std::int64_t denominator) // конструктор от 2 аргументов
    : num_(numerator), den_(denominator) {
        if (0 == den_) {
            throw std::invalid_argument("Zero denumenator in Rational ctor");
        }
        update(numerator, denominator);
    }

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
    Rational& operator+=(const std::int64_t rhs) noexcept;

    // сложение с рациональным числом с присвоением
    Rational& operator+=(const Rational& rhs) noexcept;

    // вычитание целого числа с присвоением
    Rational& operator-=(const std::int64_t rhs) noexcept;

    // вычитание рационального числа с присвоением
    Rational& operator-=(const Rational& rhs) noexcept;

    // умножение на целое числа с присвоением
    Rational& operator*=(const std::int64_t rhs) noexcept;

    // умножение на рациональное число с присвоением
    Rational& operator*=(const Rational& rhs) noexcept;

    // деление на целое число с присвоением
    Rational& operator/=(const std::int64_t rhs);

    // деление на рациональное число с присвоением
    Rational& operator/=(const Rational& rhs);

    // сравнение на равенство
    bool operator==(const Rational& rhs) const noexcept;

    // сравнение на больше
    bool operator>(const Rational &rhs) const noexcept;

    // Форматированный вывод в поток outstream рационального числа в виде {num/den}
    std::ostream& write(std::ostream& outstream) const noexcept;

    // Форматированный ввод в поток instream рационального числа в виде {num/den}
    std::istream& read(std::istream& instream) noexcept;

    // нахождение gcd двух чисел
    static std::int64_t gcd(std::int64_t lhs, std::int64_t rhs);
};

// сложение рационального числа и рационального числа
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;

// сложение целого числа и рационального числа
Rational operator+(const std::int64_t lhs, const Rational& rhs) noexcept;

// сложение рационального числа и целого числа
Rational operator+(const Rational& lhs, const std::int64_t rhs) noexcept;

// вычитание рационального числа из рационального числа
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;

// вычитание целого числа из рационального числа
Rational operator-(const Rational& lhs, const std::int64_t rhs) noexcept;

// вычитание рационального числа из целого числа
Rational operator-(const std::int64_t lhs, const Rational& rhs) noexcept;

// умножение рационального числа на рациональное число
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;

// умножение рационального числа на целое число
Rational operator*(const Rational& lhs, const std::int64_t rhs) noexcept;

// умножение целого числа на рациональное число
Rational operator*(const std::int64_t lhs, const Rational& rhs) noexcept;

// деление рационального числа на рациональное число
Rational operator/(const Rational& lhs, const Rational& rhs);

// деление рационального числа на целое число
Rational operator/(const Rational& lhs, const std::int64_t rhs);

// деление целого числа на рациональное число
Rational operator/(const std::int64_t lhs, const Rational& rhs);

// операция больше для рационального и целого числа
bool operator>(const Rational& lhs, const std::int64_t rhs) noexcept;

// операция больше для целого и рационального числа
bool operator>(const std::int64_t lhs, const Rational& rhs) noexcept;

// операция не меньше для рационального числа и рационального числа
bool operator>=(const Rational& lhs, const Rational& rhs) noexcept;

// операция не меньше для рационального числа и целого числа
bool operator>=(const Rational& lhs, const std::int64_t rhs) noexcept;

// операция не меньше для целого числа и рационального числа
bool operator>=(const std::int64_t lhs, const Rational& rhs) noexcept;

// операция меньше для рационального числа и рационального числа
bool operator<(const Rational& lhs, const Rational& rhs) noexcept;

// операция меньше для рационального числа и целого числа
bool operator<(const Rational& lhs, const std::int64_t rhs) noexcept;

// операция меньше для целого числа и рационального числа
bool operator<(const std::int64_t lhs, const Rational& rhs) noexcept;

// операция не больше для рационального числа и рационального числа
bool operator<=(const Rational& lhs, const Rational& rhs) noexcept;

// операция не больше для рационального числа и целого числа
bool operator<=(const Rational& lhs, const std::int64_t rhs) noexcept;

// операция не больше для целого числа и рационального числа
bool operator<=(const std::int64_t lhs, const Rational& rhs) noexcept;

// операция сравнения на равенство рационального числа и целого числа
bool operator==(const Rational& lhs, const std::int64_t rhs) noexcept;

// операция сравнения на равенство целого числа и рационального числа
bool operator==(const std::int64_t lhs, const Rational& rhs) noexcept;

// операция сравнения на неравенство рационального числа и рационального числа
bool operator!=(const Rational& lhs, const Rational& rhs) noexcept;

// операция сравнения на неравенство рационального числа и целого числа
bool operator!=(const Rational& lhs, const std::int64_t rhs) noexcept;

// операция сравнения на неравенство целого числа и рационального числа
bool operator!=(const std::int64_t lhs, const Rational& rhs) noexcept;

// форматированный вывод в поток outstream рационального числа
inline std::ostream& operator<<(std::ostream& outstream, const Rational& rhs) noexcept { return rhs.write(outstream); }

// Форматированный ввод из потока instream рационального числа
inline std::istream& operator>>(std::istream& instream, Rational& rhs) noexcept { return rhs.read(instream); }

#endif //RATIONAL_HPP