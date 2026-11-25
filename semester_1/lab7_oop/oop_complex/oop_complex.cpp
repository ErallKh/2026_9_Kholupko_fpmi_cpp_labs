#include "oop_complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() : re_(0.0), im_(0.0) {}

Complex::Complex(double value, bool is_imag)
    : re_(is_imag ? 0.0 : value), im_(is_imag ? value : 0.0) {}

Complex::Complex(double re, double im) : re_(re), im_(im) {}

Complex::Complex(const Complex& other) : re_(other.re_), im_(other.im_) {}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re_ = other.re_;
        im_ = other.im_;
    }
    return *this;
}

Complex::~Complex() {}

bool Complex::operator==(const Complex& other) const {
    return re_ == other.re_ && im_ == other.im_;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator+() const {
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-re_, -im_);
}

double Complex::Real() const { return re_; }
double Complex::Imag() const { return im_; }

double Complex::Abs() const {
    return std::sqrt(re_ * re_ + im_ * im_);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re_ + other.re_, im_ + other.im_);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re_ - other.re_, im_ - other.im_);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re_ * other.re_ - im_ * other.im_,
                   re_ * other.im_ + im_ * other.re_);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.re_ * other.re_ + other.im_ * other.im_;
    return Complex((re_ * other.re_ + im_ * other.im_) / denom,
                   (im_ * other.re_ - re_ * other.im_) / denom);
}

Complex Complex::operator+(double value) const {
    return Complex(re_ + value, im_);
}

Complex Complex::operator-(double value) const {
    return Complex(re_ - value, im_);
}

Complex Complex::operator*(double value) const {
    return Complex(re_ * value, im_ * value);
}

Complex Complex::operator/(double value) const {
    return Complex(re_ / value, im_ / value);
}

Complex& Complex::operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

Complex& Complex::operator+=(double value) {
    re_ += value;
    return *this;
}

Complex& Complex::operator-=(double value) {
    re_ -= value;
    return *this;
}

Complex& Complex::operator*=(double value) {
    re_ *= value;
    im_ *= value;
    return *this;
}

Complex& Complex::operator/=(double value) {
    re_ /= value;
    im_ /= value;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re_;
    if (c.im_ >= 0) {
        os << "+" << c.im_ << "i";
    } else {
        os << c.im_ << "i";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    double re, im;
    char sign, i;
    is >> re >> sign >> im >> i;
    if (sign == '-') {
        im = -im;
    }
    c.re_ = re;
    c.im_ = im;
    return is;
}

Complex operator+(double value, const Complex& c) {
    return c + value;
}

Complex operator-(double value, const Complex& c) {
    return Complex(value - c.Real(), -c.Imag());
}

Complex operator*(double value, const Complex& c) {
    return c * value;
}

Complex operator/(double value, const Complex& c) {
    double denom = c.Real() * c.Real() + c.Imag() * c.Imag();
    return Complex(value * c.Real() / denom, -value * c.Imag() / denom);
}
