#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>

// Lớp Point đại diện cho tọa độ điểm trong không gian 2D
class Point {
public:
    float x, y;

    Point();
    Point(float x_val, float y_val);

    void Nhap();
    void Xuat() const;
};

// Lớp Triangle đại diện cho tam giác với các đỉnh A, B, C
class Triangle {
private:
    Point A, B, C;

public:
    Triangle();
    Triangle(Point a, Point b, Point c);

    void Nhap();
    void Xuat() const;

    void TinhTien(float dx, float dy);
    void PhongTo(float scale);
    void ThuNho(float scale);
    void Quay(float angle);  // Quay quanh gốc tọa độ theo góc angle (radian)
};

#endif
