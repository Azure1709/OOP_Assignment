#include "DaGiac.h"

int main() {
    DaGiac dg;
    dg.Nhap();
    cout << "Da giac: ";
    dg.Xuat();

    dg.TinhTien(2, 3);
    cout << "Da giac sau khi tinh tien (2, 3): ";
    dg.Xuat();

    dg.PhongTo(2);
    cout << "Da giac sau khi phong to: ";
    dg.Xuat();

    dg.ThuNho(2);
    cout << "Da giac sau khi thu nho: ";
    dg.Xuat();

    dg.Quay(M_PI / 4); 
    cout << "Da giac sau khi quay 45 do: ";
    dg.Xuat();

    return 0;
}