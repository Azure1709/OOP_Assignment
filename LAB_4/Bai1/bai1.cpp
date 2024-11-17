#include "bai1.h"
#include <iostream>
#include <iomanip> 
using namespace std;

void NhanVien::Xuat() const {
    cout << "Ma so: " << maSo << endl;
    cout << "Ten: " << ten << endl;
    cout << "Luong co ban: " << fixed << setprecision(0) << luongCoBan << endl;
}

void QuanLy::Xuat() const {
    NhanVien::Xuat(); 
    cout << "Ty le thuong: " << fixed << setprecision(2) << tyLeThuong << endl;
    cout << "Tien thuong: " << fixed << setprecision(0) << TienThuong() << endl;
}

void KySu::Xuat() const {
    NhanVien::Xuat(); 
    cout << "So gio lam them: " << soGioLamThem << endl;
    cout << "Tien thuong: " << fixed << setprecision(0) << TienThuong() << endl;
}

