#include "DaGiac.h"
#include <bits/stdc++.h>


Diem::Diem(float x, float y) : x(x), y(y) {}

void Diem::Nhap() {
    cout << "Nhap toa do (x, y): ";
    cin >> x >> y;
}

void Diem::Xuat() const {
    cout << "(" << x << ", " << y << ")";
}

void Diem::TinhTien(float dx, float dy) {
    x += dx;
    y += dy;
}

void Diem::Quay(float alpha) {
    float x_new = x * cos(alpha) - y * sin(alpha);
    float y_new = x * sin(alpha) + y * cos(alpha);
    x = x_new;
    y = y_new;
}

DaGiac::DaGiac(int soDinh) : n(soDinh) {
    Dinh = new Diem[n];
}

DaGiac::~DaGiac() {
    delete[] Dinh;
}

void DaGiac::Nhap() {
    cout << "Nhap so dinh da giac: ";
    cin >> n;
    Dinh = new Diem[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap dinh thu " << i + 1 << ": ";
        Dinh[i].Nhap();
    }
}

void DaGiac::Xuat() const {
    for (int i = 0; i < n; ++i) {
        Dinh[i].Xuat();
        cout << " ";
    }
    cout << '\n';
}

void DaGiac::TinhTien(float dx, float dy) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].TinhTien(dx, dy);
    }
}

void DaGiac::PhongTo(float k) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].x *= k;
        Dinh[i].y *= k;
    }
}

void DaGiac::ThuNho(float k) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].x /= k;
        Dinh[i].y /= k;
    }
}

void DaGiac::Quay(float alpha) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].Quay(alpha);
    }
}