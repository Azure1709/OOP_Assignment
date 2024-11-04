// main.cpp
#include <iostream>
#include "ThoiGian.h"

int main() {
    ThoiGian t1, t2;

    std::cout << "Nhap thoi gian t1:\n";
    std::cin >> t1;

    std::cout << "Nhap thoi gian t2:\n";
    std::cin >> t2;

    // Phép cộng
    ThoiGian sum = t1 + t2;
    std::cout << "Tong t1 + t2: " << sum << std::endl;

    // Phép trừ
    ThoiGian diff = t1 - t2;
    std::cout << "Hieu t1 - t2: " << diff << std::endl;

    // Phép cộng thêm giây
    int giayThem;
    std::cout << "Nhap so giay them vao t1: ";
    std::cin >> giayThem;
    ThoiGian t1AddSeconds = t1 + giayThem;
    std::cout << "t1 sau khi them giay: " << t1AddSeconds << std::endl;

    // Phép trừ giây
    int giayTru;
    std::cout << "Nhap so giay tru khoi t1: ";
    std::cin >> giayTru;
    ThoiGian t1SubSeconds = t1 - giayTru;
    std::cout << "t1 sau khi tru giay: " << t1SubSeconds << std::endl;

    // Kiểm tra bằng nhau
    bool isEqual = (t1 == t2);
    std::cout << "t1 == t2: " << (isEqual ? "True" : "False") << std::endl;

    // So sánh lớn hơn
    bool isGreater = (t1 > t2);
    std::cout << "t1 > t2: " << (isGreater ? "True" : "False") << std::endl;

    return 0;
}
