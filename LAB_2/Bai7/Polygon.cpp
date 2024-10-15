#include "Polygon.h"
#include <iostream>
#include <cmath> // Thu vien cho ham fabs (gia tri tuyet doi)
using namespace std;

// Constructor mac dinh
Polygon::Polygon() : n(0), x(nullptr), y(nullptr) {}

// Constructor voi tham so n la so diem
Polygon::Polygon(int n) : n(n) {
    x = new float[n];
    y = new float[n];
}

// Destructor giai phong bo nho
Polygon::~Polygon() {
    delete[] x;
    delete[] y;
}

// Nhap toa do cac diem cua da giac
void Polygon::input() {
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
}

// Tinh dien tich da giac theo cong thuc shoelace
float Polygon::calculateArea() const {
    float area = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        area += x[i] * y[i + 1] - x[i + 1] * y[i];
    }
    area += x[n - 1] * y[0] - x[0] * y[n - 1];
    return fabs(area) / 2.0; // Lay gia tri tuyet doi va chia doi
}

// Xuat dien tich cua da giac
void Polygon::displayArea() const {
    cout << calculateArea() << endl;
}
