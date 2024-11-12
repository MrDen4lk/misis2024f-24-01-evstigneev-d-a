#include <iostream>
#include <rational/rational.hpp>
#include <sstream>

int64_t Rational::gcd(int64_t lhs, int64_t rhs) {
    while (rhs) {
        lhs %= rhs;
        std::swap(lhs, rhs);
    }
    return lhs;
}

int64_t Rational::update(const int64_t numerator, const int64_t denominator, const bool type) {
    int64_t gcd_of_numbers = Rational::gcd(std::abs(numerator), std::abs(denominator));
    int64_t new_numerator = (((numerator < 0ll) + (denominator < 0ll)) == 1 ? -std::abs(numerator) : std::abs(numerator)) / gcd_of_numbers;
    return (type ? new_numerator : std::abs(denominator) / gcd_of_numbers);
}

std::pair<int64_t, int64_t> update_local(int64_t num, int64_t den) {
    int64_t gcd_of_numbers = Rational::gcd(std::abs(num), std::abs(den));
    num = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den = std::abs(den) / gcd_of_numbers;
    return {num, den};
}

std::ostream& Rational::write(std::ostream& outstream) const noexcept {
    return outstream << num << mid_point << den;
}

std::istream& Rational::read(std::istream& instream) noexcept {
    std::string input = "";
    std::getline(instream, input);
    instream.clear();
    input += " ";
    std::istringstream istrm(input);

    int64_t numerator{0};
    int64_t denominator{1};
    char mid_point{'/'};
    istrm >> numerator >> mid_point >> denominator;
    if (istrm.good()) {
        if (denominator != 0 && mid_point == Rational::mid_point) {
            std::pair<int64_t, int64_t> new_number = update_local(numerator, denominator);
            num = new_number.first;
            den = new_number.second;
        } else {
            instream.setstate(std::ios_base::failbit);
        }
    }

    return instream;
}

Rational Rational::operator-() const noexcept { return Rational(-num, den); }

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    int64_t new_num = num * rhs.den + rhs.num * den;
    int64_t new_den = den * rhs.den;
    std::pair<int64_t, int64_t> new_number = update_local(new_num, new_den);
    num = new_number.first;
    den = new_number.second;
    return *this;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept {
    num += den * rhs;
    std::pair<int64_t, int64_t> new_number = update_local(num, den);
    num = new_number.first;
    den = new_number.second;
    return *this; 
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    int64_t new_num = num * rhs.den - rhs.num * den;
    int64_t new_den = den * rhs.den;
    std::pair<int64_t, int64_t> new_number = update_local(new_num, new_den);
    num = new_number.first;
    den = new_number.second;
    return *this;
}

Rational& Rational::operator-=(const int64_t rhs) noexcept {
    num -= den * rhs;
    std::pair<int64_t, int64_t> new_number = update_local(num, den);
    num = new_number.first;
    den = new_number.second;
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num *= rhs.num;
    den *= rhs.den;
    std::pair<int64_t, int64_t> new_number = update_local(num, den);
    num = new_number.first;
    den = new_number.second;
    return *this;
}

Rational& Rational::operator*=(const int64_t rhs) noexcept {
    num *= rhs;
    std::pair<int64_t, int64_t> new_number = update_local(num, den);
    num = new_number.first;
    den = new_number.second;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    num *= rhs.den;
    den *= rhs.num;
    std::pair<int64_t, int64_t> new_number = update_local(num, den);
    num = new_number.first;
    den = new_number.second;
    return *this;
}

Rational& Rational::operator/=(const int64_t rhs) {
    den *= rhs;
    std::pair<int64_t, int64_t> new_number = update_local(num, den);
    num = new_number.first;
    den = new_number.second;
    return *this;
}

bool Rational::operator==(const Rational& rhs) const noexcept {
    return (num * rhs.den == den * rhs.num);
}

bool Rational::operator>(const Rational& rhs) const noexcept {
    return (num * rhs.den > rhs.num * den);
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) += rhs);
}

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) += rhs);
}

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept {
    return (Rational(lhs) += rhs);
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) -= rhs);
}

Rational operator-(const int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) -= rhs);
}

Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
    return (Rational(lhs) -= rhs);
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) *= rhs);
}

Rational operator*(const int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) *= rhs);
}

Rational operator*(const Rational& lhs, const int64_t rhs) noexcept {
    return (Rational(lhs) *= rhs);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return (Rational(lhs) /= rhs);
}

Rational operator/(const int64_t lhs, const Rational& rhs) {
    return (Rational(lhs) /= rhs);
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
    return (Rational(lhs) /= rhs);
}

bool operator>(const int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) > rhs);
}

bool operator>(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs > Rational(rhs));
}

bool operator>=(const Rational& lhs, const Rational& rhs) noexcept {
    return ((lhs > rhs) || (lhs == rhs));
}

bool operator>=(const int64_t lhs, const Rational& rhs) noexcept {
    return ((Rational(lhs) > rhs) || (Rational(lhs) == rhs));
}

bool operator>=(const Rational& lhs, const int64_t rhs) noexcept {
    return ((lhs > Rational(rhs)) || (lhs == Rational(rhs)));
}

bool operator<(const Rational& lhs, const Rational& rhs) noexcept {
    return (!(lhs > rhs) && !(lhs == rhs));
}

bool operator<(const int64_t lhs, const Rational& rhs) noexcept {
    return (!(Rational(lhs) > rhs) && !(Rational(lhs) == rhs));
}

bool operator<(const Rational& lhs, const int64_t rhs) noexcept {
    return (!(lhs > Rational(rhs)) && !(lhs == Rational(rhs)));
}

bool operator<=(const Rational& lhs, const Rational& rhs) noexcept {
    return (!(lhs > rhs));
}

bool operator<=(const int64_t lhs, const Rational& rhs) noexcept {
    return (!(Rational(lhs) > rhs));
}

bool operator<=(const Rational& lhs, const int64_t rhs) noexcept {
    return (!(lhs > Rational(rhs)));
}

bool operator==(const Rational& lhs, const int64_t rhs) noexcept {
    return (lhs == Rational(rhs));
}

bool operator==(const int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) == rhs);
}

bool operator!=(const Rational& lhs, const Rational& rhs) noexcept {
    return (!(lhs == rhs));
}

bool operator!=(const int64_t lhs, const Rational& rhs) noexcept {
    return (!(Rational(lhs) == rhs));
}

bool operator!=(const Rational& lhs, const int64_t rhs) noexcept {
    return (!(lhs == Rational(rhs)));
}