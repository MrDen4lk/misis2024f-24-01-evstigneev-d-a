#include <iostream>
#include <rational/rational.hpp>
#include <sstream>
#include <numeric>

std::ostream& Rational::write(std::ostream& outstream) const noexcept {
    return outstream << num << mid_point << den;
}

std::istream& Rational::read(std::istream& instream) noexcept {
    int64_t numerator{0};
    int64_t denominator{1};
    char mid_point{'/'};
    std::cout << "! " << instream.good() << std::endl;
    instream >> numerator >> mid_point >> denominator;
    std::cout << "! " << instream.good() << std::endl;
    if (instream.good()) {
        if (mid_point == Rational::mid_point) {
            int64_t gcd_of_numbers = std::gcd(std::abs(numerator), std::abs(denominator));
            num = (((numerator < 0ll) + (denominator < 0ll)) == 1 ? -std::abs(numerator) : std::abs(numerator)) / gcd_of_numbers;
            den = std::abs(denominator) / gcd_of_numbers;
        } else {
            instream.setstate(std::ios_base::failbit);
        }
    } else {
        std::cerr << "!: " << numerator << ' ' << mid_point << ' ' << denominator << std::endl;
    }

    return instream;
}

Rational update(int64_t lhs, int64_t rhs) {
    int64_t gcd_of_numbers = std::gcd(std::abs(lhs), std::abs(rhs));
    lhs = (((lhs < 0ll) + (rhs < 0ll)) == 1 ? -std::abs(lhs) : std::abs(lhs)) / gcd_of_numbers;
    rhs = std::abs(rhs) / gcd_of_numbers;
    return Rational(lhs, rhs);
}

Rational Rational::operator-() const noexcept { return Rational(-num, den); }

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    int64_t new_num = num * rhs.den + rhs.num * den;
    int64_t new_den = den * rhs.den;
    int64_t gcd_of_numbers = std::gcd(std::abs(new_num), std::abs(new_den));
    num = (((new_num < 0ll) + (new_den < 0ll)) == 1 ? -std::abs(new_num) : std::abs(new_num)) / gcd_of_numbers;
    den = std::abs(new_den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept {
    num += den * rhs;
    int64_t gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this; 
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    int64_t new_num = num * rhs.den - rhs.num * den;
    int64_t new_den = den * rhs.den;
    int64_t gcd_of_numbers = std::gcd(std::abs(new_num), std::abs(new_den));
    num = (((new_num < 0ll) + (new_den < 0ll)) == 1 ? -std::abs(new_num) : std::abs(new_num)) / gcd_of_numbers;
    den = std::abs(new_den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator-=(const int64_t rhs) noexcept {
    num -= den * rhs;
    int64_t gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num *= rhs.num;
    den *= rhs.den;
    int64_t gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator*=(const int64_t rhs) noexcept {
    num *= rhs;
    int64_t gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    num *= rhs.den;
    den *= rhs.num;
    int64_t gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator/=(const int64_t rhs) {
    den *= rhs;
    int64_t gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
    int64_t new_num = lhs.num * rhs.den + rhs.num * lhs.den;
    int64_t new_den = lhs.den * rhs.den;
    return update(new_num, new_den);
}

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept {
    int64_t new_num = lhs * rhs.den + rhs.num;
    int64_t new_den = rhs.den;
    return update(new_num, new_den);
}

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept {
    int64_t new_num = lhs.num + rhs * lhs.den;
    int64_t new_den = lhs.den;
    return update(new_num, new_den);
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
    int64_t new_num = lhs.num * rhs.den - rhs.num * lhs.den;
    int64_t new_den = rhs.den * lhs.den;
    return update(new_num, new_den);
}

Rational operator-(const int64_t lhs, const Rational& rhs) noexcept {
    int64_t new_num = lhs * rhs.den - rhs.num;
    int64_t new_den = rhs.den;
    return update(new_num, new_den);
}

Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
    int64_t new_num = lhs.num - lhs.den * rhs;
    int64_t new_den = lhs.den;
    return update(new_num, new_den);
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
    int64_t new_num = lhs.num * rhs.num;
    int64_t new_den = rhs.den * lhs.den;
    return update(new_num, new_den);
}

Rational operator*(const int64_t lhs, const Rational& rhs) noexcept {
    int64_t new_num = lhs * rhs.num;
    int64_t new_den = rhs.den;
    return update(new_num, new_den);
}

Rational operator*(const Rational& lhs, const int64_t rhs) noexcept {
    int64_t new_num = lhs.num * rhs;
    int64_t new_den = lhs.den;
    return update(new_num, new_den);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int64_t new_num = lhs.num * rhs.den;
    int64_t new_den = lhs.den * rhs.num;
    return update(new_num, new_den);
}

Rational operator/(const int64_t lhs, const Rational& rhs) {
    int64_t new_num = lhs * rhs.den;
    int64_t new_den = rhs.num;
    return update(new_num, new_den);
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
    int64_t new_num = lhs.num;
    int64_t new_den = lhs.den * rhs;
    return update(new_num, new_den);
}

bool operator>(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den > 0);
}

bool operator>(const int64_t lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num > 0);
}

bool operator>(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs.num - rhs * lhs.den > 0);
}

bool operator>=(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den >= 0);
}

bool operator>=(const int64_t lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num >= 0);
}

bool operator>=(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs.num - rhs * lhs.den >= 0);
}

bool operator<(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den < 0);
}

bool operator<(const int64_t lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num < 0);
}

bool operator<(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs.num - rhs * lhs.den < 0);
}

bool operator<=(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den <= 0);
}

bool operator<=(const int64_t lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num <= 0);
}

bool operator<=(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs.num - rhs * lhs.den <= 0);
}

bool operator==(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den == 0);
}

bool operator==(const int64_t lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num == 0);
}

bool operator==(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs.num - rhs * lhs.den == 0);
}

bool operator!=(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den != 0);
}

bool operator!=(const int64_t lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num != 0);
}

bool operator!=(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs.num - rhs * lhs.den != 0);
}