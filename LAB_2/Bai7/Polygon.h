#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
private:
    int n; // So diem cua da giac
    float* x; // Mang chua hoanh do cac diem
    float* y; // Mang chua tung do cac diem

public:
    Polygon(); // Constructor mac dinh
    Polygon(int n); // Constructor co tham so
    ~Polygon(); // Destructor de giai phong bo nho
    void input(); // Nhap thong tin cac diem cua da giac
    float calculateArea() const; // Tinh dien tich da giac
    void displayArea() const; // Xuat dien tich da giac
};

#endif // POLYGON_H
