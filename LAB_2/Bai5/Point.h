#ifndef POINT_H
#define POINT_H

class Point {
private:
    float x, y; // Hoanh do va tung do

public:
    Point(); // Constructor mac dinh
    Point(float x, float y); // Constructor co tham so
    void doubleCoordinates(); // Nhan doi tung do va hoanh do
    void resetToOrigin(); // Gan diem ve goc toa do
    void translate(int direction, float distance); // Tinh tien diem
    void display() const; // Xuat ra thong tin diem
};

#endif // POINT_H
