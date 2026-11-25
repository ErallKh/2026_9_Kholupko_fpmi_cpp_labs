#pragma once

#include <cmath>
#include <iostream>

class Complex {
private:
    double re_;
    double im_;

public:
    Complex();
    Complex(double value, bool is_imag = false);
    Complex(double re, double im);
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);
    ~Complex();

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    Complex operator+() const;
    Complex operator-() const;

    double Real() const;
    double Imag() const;
    double Abs() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex operator+(double value) const;
    Complex operator-(double value) const;
    Complex operator*(double value) const;
    Complex operator/(double value) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex& operator+=(double value);
    Complex& operator-=(double value);
    Complex& operator*=(double value);
    Complex& operator/=(double value);

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

Complex operator+(double value, const Complex& c);
Complex operator-(double value, const Complex& c);
Complex operator*(double value, const Complex& c);
Complex operator/(double value, const Complex& c);

#endif
