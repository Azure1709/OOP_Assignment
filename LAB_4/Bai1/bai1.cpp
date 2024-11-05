#include "bai1.h"
#include <iostream>
using namespace std;

void NhanVien::Xuat() const {
    cout << "Ma so: " << maSo << "\nTen: " << ten << "\n";
    cout << "Luong co ban: " << luongCoBan << endl;
}

void QuanLy::Xuat() const {
    NhanVien::Xuat();
    cout << "Ty le thuong: " << tyLeThuong << "\n";
    cout << "Tien thuong: " << TienThuong() << endl;
}

void KySu::Xuat() const {
    NhanVien::Xuat();
    cout << "So gio lam them: " << soGioLamThem << "\n";
    cout << "Tien thuong: " << TienThuong() << endl;
}

