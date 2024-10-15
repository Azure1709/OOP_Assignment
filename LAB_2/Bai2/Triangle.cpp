#include "Triangle.h"

// Implementation of Point methods
Point::Point() : x(0), y(0) {}
Point::Point(float x_val, float y_val) : x(x_val), y(y_val) {}

void Point::Nhap() {
    std::cout << "Nhap toa do x: ";
    std::cin >> x;
    std::cout << "Nhap toa do y: ";
    std::cin >> y;
}

void Point::Xuat() const {
    std::cout << "(" << x << ", " << y << ")";
}

// Implementation of Triangle methods
Triangle::Triangle() : A(), B(), C() {}

Triangle::Triangle(Point a, Point b, Point c) : A(a), B(b), C(c) {}

void Triangle::Nhap() {
    std::cout << "Nhap toa do dinh A:\n";
    A.Nhap();
    std::cout << "Nhap toa do dinh B:\n";
    B.Nhap();
    std::cout << "Nhap toa do dinh C:\n";
    C.Nhap();
}

void Triangle::Xuat() const {
    std::cout << "Dinh A: "; A.Xuat(); std::cout << "\n";
    std::cout << "Dinh B: "; B.Xuat(); std::cout << "\n";
    std::cout << "Dinh C: "; C.Xuat(); std::cout << "\n";
}

void Triangle::TinhTien(float dx, float dy) {
    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}

void Triangle::PhongTo(float scale) {
    A.x *= scale; A.y *= scale;
    B.x *= scale; B.y *= scale;
    C.x *= scale; C.y *= scale;
}

void Triangle::ThuNho(float scale) {
    if (scale != 0) {
        A.x /= scale; A.y /= scale;
        B.x /= scale; B.y /= scale;
        C.x /= scale; C.y /= scale;
    }
}

void Triangle::Quay(float angle) {
    float cosA = cos(angle);
    float sinA = sin(angle);

    // Quay điểm A
    float x_new = A.x * cosA - A.y * sinA;
    float y_new = A.x * sinA + A.y * cosA;
    A.x = x_new; A.y = y_new;

    // Quay điểm B
    x_new = B.x * cosA - B.y * sinA;
    y_new = B.x * sinA + B.y * cosA;
    B.x = x_new; B.y = y_new;

    // Quay điểm C
    x_new = C.x * cosA - C.y * sinA;
    y_new = C.x * sinA + C.y * cosA;
    C.x = x_new; C.y = y_new;
}
