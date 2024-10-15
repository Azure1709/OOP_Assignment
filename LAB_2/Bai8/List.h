#ifndef LIST_H
#define LIST_H

class List {
private:
    double* arr;           // Con tro quan ly mang
    unsigned int size;     // Kich thuoc cua list

public:
    List();                // Constructor khoi tao list rong
    ~List();               // Destructor de giai phong bo nho

    void add(double x);    // Them phan tu vao list
    void removeFirst(double x); // Xoa phan tu dau tien co gia tri x
    void removeAll(double x);    // Xoa tat ca phan tu co gia tri x
    void update(int index, double y); // Cap nhat phan tu thu index thanh y
    void print() const;    // In ra list
};

#endif // LIST_H
