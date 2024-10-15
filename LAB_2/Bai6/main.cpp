#include <iostream>
#include "Triangle.h"
using namespace std;

int main() {
    float x1, y1, x2, y2, x3, y3;
    float direction, distance;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Tao doi tuong tam giac
    Triangle triangle(x1, y1, x2, y2, x3, y3);

    // Nhap huong tinh tien va do dai tinh tien
    cin >> direction >> distance;

    // thuc hien
    triangle.translate(direction, distance);

    // Xuat
    triangle.display();

    return 0;
}
