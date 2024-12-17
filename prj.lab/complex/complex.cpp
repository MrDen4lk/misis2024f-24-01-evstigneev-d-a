#include <complex/complex.hpp>
#include <sstream>
#include <stdexcept>
#include <cmath>

std::ostream& Complex::write(std::ostream& outstream) const noexcept {
    return outstream << left_point << re << mid_point << im << right_point;
}

std::istream& Complex::read(std::istream& instream) noexcept {
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

bool operator==(const Complex& lhs, const Complex& rhs) noexcept { 
    return ((abs(rhs.re - lhs.re) < 2 * std::numeric_limits<double>::epsilon())
    && (abs(rhs.im - lhs.im) < 2 * std::numeric_limits<double>::epsilon()));
}

bool operator!=(const Complex& lhs, const Complex& rhs) noexcept {  return !(lhs == rhs); }

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs) += rhs;
}

Complex operator+(const double lhs, const Complex& rhs) noexcept {
    return Complex(lhs) += rhs;
}

Complex operator+(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs) += rhs;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs) -= rhs;
}

Complex operator-(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs) -= rhs;
}

Complex operator-(const double lhs, const Complex& rhs) noexcept {
    return Complex(lhs) -= rhs;
}

Complex operator*(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs) *= rhs;
}

Complex operator*(const double lhs, const Complex& rhs) noexcept {
    return Complex(lhs) *= rhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs) *= rhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs) /= rhs;
}

Complex operator/(const Complex& lhs, const double rhs) {
    return Complex(lhs) /= rhs;
}

Complex operator/(const double lhs, const Complex& rhs) {
    return Complex(lhs) /= rhs;
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
    re += rhs.re;
    im += rhs.im;
    return *this; 
}

Complex& Complex::operator+=(const double rhs) noexcept {
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept {
    return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
    const double new_re = re * rhs.re - im * rhs.im;
    const double new_im = re * rhs.im + im * rhs.re;
    re = new_re;
    im = new_im;
    return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept {
    return operator*=(Complex(rhs));
}

Complex& Complex::operator/=(const Complex& rhs) {
    if (rhs.re == 0.0 && rhs.im == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    const double new_re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    const double new_im = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    re = new_re;
    im = new_im;
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    return operator/=(Complex(rhs));
}
