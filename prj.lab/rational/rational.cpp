#include <rational/rational.hpp>
#include <sstream>
#include <numeric>
#include <iostream>

std::ostream& Rational::write(std::ostream& outstream) const noexcept {
    return outstream << left_point << num << mid_point << den << right_point;
}

std::istream& Rational::read(std::istream& instream) noexcept {
    int numerator(1);
    int denominator(1);
    char mid_point(0);
    char left_point(0);
    char right_point(0);

    instream >> left_point >> numerator >> mid_point >> denominator >> right_point;
    if (instream.good()) {
        if (left_point == Rational::left_point && mid_point == Rational::mid_point && right_point == Rational::right_point && denominator != 0) {
            long long gcd_of_numbers = std::gcd(std::abs(numerator), std::abs(denominator));
            num = (((numerator < 0ll) + (denominator < 0ll)) == 1 ? -std::abs(numerator) : std::abs(numerator)) / gcd_of_numbers;
            den = std::abs(denominator) / gcd_of_numbers;
        } else {
            instream.setstate(std::ios_base::failbit);
        }
    }

    return instream;
}

Rational update(long long lhs, long long rhs) {
    long long gcd_of_numbers = std::gcd(std::abs(lhs), std::abs(rhs));
    lhs = (((lhs < 0ll) + (rhs < 0ll)) == 1 ? -std::abs(lhs) : std::abs(lhs)) / gcd_of_numbers;
    rhs = std::abs(rhs) / gcd_of_numbers;
    return Rational(lhs, rhs);
}

Rational Rational::operator-() const noexcept { return Rational(-num, den); }

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    long long new_num = num * rhs.den + rhs.num * den;
    long long new_den = den * rhs.den;
    long long gcd_of_numbers = std::gcd(std::abs(new_num), std::abs(new_den));
    num = (((new_num < 0ll) + (new_den < 0ll)) == 1 ? -std::abs(new_num) : std::abs(new_num)) / gcd_of_numbers;
    den = std::abs(new_den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator+=(const long long rhs) noexcept {
    num += den * rhs;
    long long gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this; 
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    long long new_num = num * rhs.den - rhs.num * den;
    long long new_den = den * rhs.den;
    long long gcd_of_numbers = std::gcd(std::abs(new_num), std::abs(new_den));
    num = (((new_num < 0ll) + (new_den < 0ll)) == 1 ? -std::abs(new_num) : std::abs(new_num)) / gcd_of_numbers;
    den = std::abs(new_den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator-=(const long long rhs) noexcept {
    num -= den * rhs;
    long long gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num *= rhs.num;
    den *= rhs.den;
    long long gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator*=(const long long rhs) noexcept {
    num *= rhs;
    long long gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    num *= rhs.den;
    den *= rhs.num;
    long long gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational& Rational::operator/=(const long long rhs) {
    den *= rhs;
    long long gcd_of_numbers = std::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
    long long new_num = lhs.num * rhs.den + rhs.num * lhs.den;
    long long new_den = lhs.den * rhs.den;
    return update(new_num, new_den);
}

Rational operator+(const long long lhs, const Rational& rhs) noexcept {
    long long new_num = lhs * rhs.den + rhs.num;
    long long new_den = rhs.den;
    return update(new_num, new_den);
}

Rational operator+(const Rational& lhs, const long long rhs) noexcept {
    long long new_num = lhs.num + rhs * lhs.den;
    long long new_den = lhs.den;
    return update(new_num, new_den);
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
    long long new_num = lhs.num * rhs.den - rhs.num * lhs.den;
    long long new_den = rhs.den * lhs.den;
    return update(new_num, new_den);
}

Rational operator-(const long long lhs, const Rational& rhs) noexcept {
    long long new_num = lhs * rhs.den - rhs.num;
    long long new_den = rhs.den;
    return update(new_num, new_den);
}

Rational operator-(const Rational& lhs, const long long rhs) noexcept {
    long long new_num = lhs.num - lhs.den * rhs;
    long long new_den = lhs.den;
    return update(new_num, new_den);
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
    long long new_num = lhs.num * rhs.num;
    long long new_den = rhs.den * lhs.den;
    return update(new_num, new_den);
}

Rational operator*(const long long lhs, const Rational& rhs) noexcept {
    long long new_num = lhs * rhs.num;
    long long new_den = rhs.den;
    return update(new_num, new_den);
}

Rational operator*(const Rational& lhs, const long long rhs) noexcept {
    long long new_num = lhs.num * rhs;
    long long new_den = lhs.den;
    return update(new_num, new_den);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    long long new_num = lhs.num * rhs.den;
    long long new_den = lhs.den * rhs.num;
    return update(new_num, new_den);
}

Rational operator/(const long long lhs, const Rational& rhs) {
    long long new_num = lhs * rhs.den;
    long long new_den = rhs.num;
    return update(new_num, new_den);
}

Rational operator/(const Rational& lhs, const long long rhs) {
    long long new_num = lhs.num;
    long long new_den = lhs.den * rhs;
    return update(new_num, new_den);
}

bool operator>(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den > 0);
}

bool operator>(const long long lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num > 0);
}

bool operator>(const Rational& lhs, const long long rhs) noexcept {
    return (lhs.num - rhs * lhs.den > 0);
}

bool operator>=(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den >= 0);
}

bool operator>=(const long long lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num >= 0);
}

bool operator>=(const Rational& lhs, const long long rhs) noexcept {
    return (lhs.num - rhs * lhs.den >= 0);
}

bool operator<(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den < 0);
}

bool operator<(const long long lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num < 0);
}

bool operator<(const Rational& lhs, const long long rhs) noexcept {
    return (lhs.num - rhs * lhs.den < 0);
}

bool operator<=(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den <= 0);
}

bool operator<=(const long long lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num <= 0);
}

bool operator<=(const Rational& lhs, const long long rhs) noexcept {
    return (lhs.num - rhs * lhs.den <= 0);
}

bool operator==(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den == 0);
}

bool operator==(const long long lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num == 0);
}

bool operator==(const Rational& lhs, const long long rhs) noexcept {
    return (lhs.num - rhs * lhs.den == 0);
}

bool operator!=(const Rational& lhs, const Rational& rhs) noexcept {
    return (lhs.num * rhs.den - rhs.num * lhs.den != 0);
}

bool operator!=(const long long lhs, const Rational& rhs) noexcept {
    return (lhs * rhs.den - rhs.num != 0);
}

bool operator!=(const Rational& lhs, const long long rhs) noexcept {
    return (lhs.num - rhs * lhs.den != 0);
}