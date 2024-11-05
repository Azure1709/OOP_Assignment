#include "bai1.h"
#include <iostream>
using namespace std;

int main() {
    string maSo, ten;
    double luongCoBan, tyLeThuong;
    int soGioLamThem;

    cout << "Nhap thong tin quan ly:\n";
    cout << "Ma so: "; 
    cin >> maSo;
    cout << "Ten: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Luong co ban: ";
    cin >> luongCoBan;
    cout << "Ty le thuong: ";
    cin >> tyLeThuong;

    QuanLy ql(maSo, ten, luongCoBan, tyLeThuong);

    cout << "\nNhap thong tin ky su:\n";
    cout << "Ma so: ";
    cin >> maSo;
    cout << "Ten: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Luong co ban: ";
    cin >> luongCoBan;
    cout << "So gio lam them: ";
    cin >> soGioLamThem;

    KySu ks(maSo, ten, luongCoBan, soGioLamThem);

    cout << "\nThong tin quan ly:" << endl;
    ql.Xuat();

    cout << "\nThong tin ky su:" << endl;
    ks.Xuat();

    return 0;
}
