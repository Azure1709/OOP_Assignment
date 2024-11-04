// Complex.cpp
#include "Complex.h"
#include <iostream>
#include <cmath>

Complex::Complex() : dThuc(0), dAo(0) {}

Complex::Complex(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(dThuc + other.dThuc, dAo + other.dAo);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(dThuc - other.dThuc, dAo - other.dAo);
}

Complex Complex::operator*(const Complex& other) const {
    double real = dThuc * other.dThuc - dAo * other.dAo;
    double imaginary = dThuc * other.dAo + dAo * other.dThuc;
    return Complex(real, imaginary);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.dThuc * other.dThuc + other.dAo * other.dAo;
    double real = (dThuc * other.dThuc + dAo * other.dAo) / denominator;
    double imaginary = (dAo * other.dThuc - dThuc * other.dAo) / denominator;
    return Complex(real, imaginary);
}

bool Complex::operator==(const Complex& other) const {
    return dThuc == other.dThuc && dAo == other.dAo;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.dThuc << " + " << c.dAo << "i";
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c) {
    std::cout << "Enter real part: ";
    in >> c.dThuc;
    std::cout << "Enter imaginary part: ";
    in >> c.dAo;
    return in;
}
