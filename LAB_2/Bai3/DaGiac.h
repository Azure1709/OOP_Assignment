#ifndef DAGIAC_H
#define DAGIAC_H

#include <bits/stdc++.h>
using namespace std;

class Diem {
public:
    float x, y;

    Diem(float x = 0, float y = 0);

    void Nhap();
    void Xuat() const;
    void TinhTien(float dx, float dy);
    void Quay(float alpha);
};


class DaGiac {
private:
    int n;    
    Diem* Dinh; 

public:
    DaGiac(int soDinh = 3);
    ~DaGiac(); 

    void Nhap();
    void Xuat() const;
    void TinhTien(float dx, float dy);
    void PhongTo(float k);
    void ThuNho(float k);
    void Quay(float alpha);
};

#endif