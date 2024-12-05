#include <complex/complex.hpp>
#include <sstream>
#include <stdexcept>

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
    return ((std::fabs(rhs.re - lhs.re) < std::numeric_limits<double>::epsilon())
    && (std::fabs(rhs.im - lhs.im) < std::numeric_limits<double>::epsilon()));
    }

bool operator!=(const Complex& lhs, const Complex& rhs) noexcept {  { return !(lhs == rhs); }; }

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(rhs.re + lhs.re, rhs.im + lhs.im);
}

Complex operator+(const double lhs, const Complex& rhs) noexcept {
    return Complex(rhs.re + lhs, rhs.im);
}

Complex operator+(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs.re + rhs, lhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs.re - rhs, lhs.im);
}

Complex operator-(const double lhs, const Complex& rhs) noexcept {
    return Complex(lhs - rhs.re, -rhs.im);
}

Complex operator*(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs.re * rhs, lhs.im * rhs);
}

Complex operator*(const double lhs, const Complex& rhs) noexcept {
    return Complex(lhs * rhs.re, lhs * rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + lhs.im * rhs.re);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    if (rhs.re == 0.0 && rhs.im == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    double re = (lhs.re * lhs.im + rhs.re * rhs.im) / (lhs.im * lhs.im + rhs.im * rhs.im);
    double im = (lhs.im * rhs.re - lhs.re * rhs.im) / (lhs.im * lhs.im + rhs.im * rhs.im);
    return Complex(re, im);
}

Complex operator/(const Complex& lhs, const double rhs) {
    if (rhs == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex(lhs.re / rhs, lhs.im / rhs);
}

Complex operator/(const double lhs, const Complex& rhs) {
    if (rhs.re == 0.0 && rhs.im == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex(lhs / rhs.re, lhs / rhs.im);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
    re += rhs.re;
    im += rhs.im;
    return *this; 
}

Complex& Complex::operator+=(const double rhs) noexcept {
    re += rhs;
    return *this; 
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept {
    re -= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
    double new_re = re * rhs.re - im * rhs.im;
    double new_im = re * rhs.im + im * rhs.re;
    re = new_re;
    im = new_im;
    return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept {
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    if (rhs.re == 0.0 && rhs.im == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    double new_re = (re * im + rhs.re * rhs.im) / (im * im + rhs.im * rhs.im);
    double new_im = (im * rhs.re - re * rhs.im) / (im * im + rhs.im * rhs.im);
    re = new_re;
    im = new_im;
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    if (rhs == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    re /= rhs;
    im /= rhs;
    return *this;
}
