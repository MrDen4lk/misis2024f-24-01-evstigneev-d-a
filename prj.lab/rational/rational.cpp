#include <iostream>
#include <rational/rational.hpp>
#include <sstream>
#include <cstdint>
#include <stdexcept>

std::int64_t Rational::gcd(std::int64_t lhs, std::int64_t rhs) {
    while (rhs) {
        lhs %= rhs;
        std::swap(lhs, rhs);
    }
    return lhs;
}

void Rational::update(std::int64_t num, std::int64_t den) {
    std::int64_t gcd_of_numbers = gcd(std::abs(num), std::abs(den));
    num_ = (((num < 0ll) + (den < 0ll)) == 1 ? -std::abs(num) : std::abs(num)) / gcd_of_numbers;
    den_ = std::abs(den) / gcd_of_numbers;
}

std::ostream& Rational::write(std::ostream& outstream) const noexcept {
    return outstream << num_ << mid_point << den_;
}

std::istream& Rational::read(std::istream& instream) noexcept {
    std::string input = std::string();
    std::getline(instream, input);
    instream.clear();
    input += " ";
    std::istringstream istrm(input);

    std::int64_t numerator{0};
    std::int64_t denominator{1};
    char mid_point{'/'};
    istrm >> numerator >> mid_point >> denominator;
    if (denominator == 0) {
        throw std::out_of_range("Zero denominator");
    }
    if (istrm.good()) {
        if (denominator != 0 && mid_point == Rational::mid_point) {
            update(numerator, denominator);
        } else {
            instream.setstate(std::ios_base::failbit);
        }
    }

    return instream;
}

Rational Rational::operator-() const noexcept { return Rational(-num_, den_); }

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    std::int64_t new_num = num_ * rhs.den_ + rhs.num_ * den_;
    std::int64_t new_den = den_ * rhs.den_;
    update(new_num, new_den);
    return *this;
}

Rational& Rational::operator+=(const std::int64_t rhs) noexcept {
    num_ += den_ * rhs;
    update(num_, den_);
    return *this; 
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    std::int64_t new_num = num_ * rhs.den_ - rhs.num_ * den_;
    std::int64_t new_den = den_ * rhs.den_;
    update(new_num, new_den);
    return *this;
}

Rational& Rational::operator-=(const std::int64_t rhs) noexcept {
    num_ -= den_ * rhs;
    update(num_, den_);
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    update(num_, den_);
    return *this;
}

Rational& Rational::operator*=(const std::int64_t rhs) noexcept {
    num_ *= rhs;
    update(num_, den_);
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num_ == 0) {
        throw std::out_of_range("Division by zero");
    }
    num_ *= rhs.den_;
    den_ *= rhs.num_;
    update(num_, den_);
    return *this;
}

Rational& Rational::operator/=(const std::int64_t rhs) {
    if (rhs == 0) {
        throw std::out_of_range("Division by zero");
    }
    den_ *= rhs;
    update(num_, den_);
    return *this;
}

bool Rational::operator==(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ == den_ * rhs.num_);
}

bool Rational::operator>(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ > rhs.num_ * den_);
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) += rhs);
}

Rational operator+(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) += rhs);
}

Rational operator+(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (Rational(lhs) += rhs);
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) -= rhs);
}

Rational operator-(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) -= rhs);
}

Rational operator-(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (Rational(lhs) -= rhs);
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) *= rhs);
}

Rational operator*(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) *= rhs);
}

Rational operator*(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (Rational(lhs) *= rhs);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return (Rational(lhs) /= rhs);
}

Rational operator/(const std::int64_t lhs, const Rational& rhs) {
    return (Rational(lhs) /= rhs);
}

Rational operator/(const Rational& lhs, const std::int64_t rhs) {
    return (Rational(lhs) /= rhs);
}

bool operator>(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) > rhs);
}

bool operator>(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (lhs > Rational(rhs));
}

bool operator>=(const Rational& lhs, const Rational& rhs) noexcept {
    return ((lhs > rhs) || (lhs == rhs));
}

bool operator>=(const std::int64_t lhs, const Rational& rhs) noexcept {
    return ((Rational(lhs) > rhs) || (Rational(lhs) == rhs));
}

bool operator>=(const Rational& lhs, const std::int64_t rhs) noexcept {
    return ((lhs > Rational(rhs)) || (lhs == Rational(rhs)));
}

bool operator<(const Rational& lhs, const Rational& rhs) noexcept {
    return (!(lhs > rhs) && !(lhs == rhs));
}

bool operator<(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (!(Rational(lhs) > rhs) && !(Rational(lhs) == rhs));
}

bool operator<(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (!(lhs > Rational(rhs)) && !(lhs == Rational(rhs)));
}

bool operator<=(const Rational& lhs, const Rational& rhs) noexcept {
    return (!(lhs > rhs));
}

bool operator<=(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (!(Rational(lhs) > rhs));
}

bool operator<=(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (!(lhs > Rational(rhs)));
}

bool operator==(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (lhs == Rational(rhs));
}

bool operator==(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (Rational(lhs) == rhs);
}

bool operator!=(const Rational& lhs, const Rational& rhs) noexcept {
    return (!(lhs == rhs));
}

bool operator!=(const std::int64_t lhs, const Rational& rhs) noexcept {
    return (!(Rational(lhs) == rhs));
}

bool operator!=(const Rational& lhs, const std::int64_t rhs) noexcept {
    return (!(lhs == Rational(rhs)));
}