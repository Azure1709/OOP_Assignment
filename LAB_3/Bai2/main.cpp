// main.cpp
#include <iostream>
#include "Complex.h"

int main() {
    Complex c1, c2;

    // Nhập số phức c1
    std::cout << "Nhap so phuc c1:\n";
    std::cin >> c1;

    // Nhập số phức c2
    std::cout << "Nhap so phuc c2:\n";
    std::cin >> c2;

    // Phép cộng
    Complex sum = c1 + c2;
    std::cout << "Tong: " << sum << std::endl;

    // Phép trừ
    Complex diff = c1 - c2;
    std::cout << "Hieu: " << diff << std::endl;

    // Phép nhân
    Complex prod = c1 * c2;
    std::cout << "Tich: " << prod << std::endl;

    // Phép chia
    Complex quotient = c1 / c2;
    std::cout << "Thuong: " << quotient << std::endl;

    // Kiểm tra bằng nhau
    bool isEqual = (c1 == c2);
    std::cout << "c1 == c2: " << (isEqual ? "True" : "False") << std::endl;

    // Kiểm tra khác nhau
    bool isNotEqual = (c1 != c2);
    std::cout << "c1 != c2: " << (isNotEqual ? "True" : "False") << std::endl;

    return 0;
}
