#include "Triangle.h"
#include <iostream>

int main() {
    Triangle triangle;
    
    // Nhập tam giác
    std::cout << "Nhap thong tin tam giac:\n";
    triangle.Nhap();

    // Xuất tam giác ban đầu
    std::cout << "\nTam giac vua nhap:\n";
    triangle.Xuat();

    // Tịnh tiến tam giác
    float dx, dy;
    std::cout << "\nNhap gia tri tinh tien (dx, dy): ";
    std::cin >> dx >> dy;
    triangle.TinhTien(dx, dy);
    std::cout << "\nTam giac sau khi tinh tien:\n";
    triangle.Xuat();

    // Phóng to tam giác
    float scale;
    std::cout << "\nNhap he so phong to: ";
    std::cin >> scale;
    triangle.PhongTo(scale);
    std::cout << "\nTam giac sau khi phong to:\n";
    triangle.Xuat();

    // Thu nhỏ tam giác
    std::cout << "\nNhap he so thu nho: ";
    std::cin >> scale;
    triangle.ThuNho(scale);
    std::cout << "\nTam giac sau khi thu nho:\n";
    triangle.Xuat();

    // Quay tam giác
    float angle;
    std::cout << "\nNhap goc quay (tinh bang radian): ";
    std::cin >> angle;
    triangle.Quay(angle);
    std::cout << "\nTam giac sau khi quay:\n";
    triangle.Xuat();

    return 0;
}
