/*
❖ Cài đặt lớp số phức để biểu diễn khái niệm số phức, cho
phép quan điểm một số thực như một số phức đặc biệt
(phần ảo bằng 0).
❖ Định nghĩa các phép toán +, -, *, /, ==, <<, >> trên số phức.
❖ Định nghĩa các thao tác cần thiết cho lớp số phức
*/

#include <bits/stdc++.h>
using namespace std;

class Complex {
private:
    double real;   // Real part
    double imag;   // Imaginary part

public:
    // Constructors
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Operator overloads
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) {
            throw runtime_error("Division by zero");
        }
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }

    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    // Friend functions for input and output
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        char sign;
        is >> c.real >> sign;
        if (sign == '+') {
            is >> c.imag;
        } else if (sign == '-') {
            is >> c.imag;
            c.imag = -c.imag; // Negate the imaginary part
        } else {
            is.setstate(ios::failbit); // Invalid input
        }
        return is;
    }

    // Method to get the absolute value of the complex number
    double abs() const {
        return sqrt(real * real + imag * imag);
    }
};

int main() {
    Complex a(3, 4);
    Complex b(1, -2);
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    
    Complex c = a + b;
    cout << "a + b: " << c << endl;
    
    Complex d = a - b;
    cout << "a - b: " << d << endl;
    
    Complex e = a * b;
    cout << "a * b: " << e << endl;
    
    Complex f = a / b;
    cout << "a / b: " << f << endl;

    // Checking equality
    cout << "a == b: " << (a == b) << endl;

    return 0;
}
