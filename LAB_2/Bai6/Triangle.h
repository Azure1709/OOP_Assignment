#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
private:
    float x1, y1, x2, y2, x3, y3; // Toa do 3 diem cua tam giac

public:
    Triangle(); // Constructor mac dinh
    // Constructor co tham so
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3); 
    // Tinh tien tam giac
    void translate(float direction, float distance); 
    void display() const;
};

#endif // TRIANGLE_H
