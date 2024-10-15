#include "Triangle.h"
#include <iostream>
#include <cmath> 
using namespace std;

const float PI = 3.14;

Triangle::Triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {} 

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3) 
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {} 

void Triangle::translate(float direction, float distance) {
    // Chuyen doi tu do sang radian
    float rad = direction * PI / 180.0;

    // Tinh cac gia tri tinh tien theo x y
    float dx = distance * cos(rad);
    float dy = distance * sin(rad);

    // Tinh tien ca 3 diem
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
}

void Triangle::display() const {
    cout << "(" << x1 << "," << y1 << ")" << endl;
    cout << "(" << x2 << "," << y2 << ")" << endl;
    cout << "(" << x3 << "," << y3 << ")" << endl;
}
