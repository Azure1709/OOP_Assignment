// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double dThuc; // Real part
    double dAo;   // Imaginary part

public:
    // Constructors
    Complex();
    Complex(double thuc, double ao);

    // Operator overloads
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Input and output stream overloads
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
};

#endif
