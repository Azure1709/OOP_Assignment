#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0) {} // Constructor mac dinh gan ve (0,0)

Point::Point(float x, float y) : x(x), y(y) {} // Constructor co tham so

void Point::doubleCoordinates() {
    x *= 2;
    y *= 2;
}

void Point::resetToOrigin() {
    x = 0;
    y = 0;
}

void Point::translate(int direction, float distance) {
    if (direction == 0) {
        x += distance; // Tinh tien theo truc x
    } else {
        y += distance; // Tinh tien theo truc y
    }
}

void Point::display() const {
    cout << "(" << x << "," << y << ")" << endl;
}
