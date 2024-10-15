#include <iostream>
#include "ThiSinh.h"
using namespace std;

// Nhap thong tin thi sinh
void ThiSinh::Nhap() {
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, Ten);
    cout << "Nhap MSSV: ";
    cin >> MSSV;
    cout << "Nhap ngay, thang, nam: ";
    cin >> iNgay >> iThang >> iNam;
    cout << "Nhap diem Toan, Van, Anh: ";
    cin >> fToan >> fVan >> fAnh;
}

// Xuat thong tin thi sinh
void ThiSinh::Xuat() const {
    cout << "Ten: " << Ten << ", MSSV: " << MSSV
         << ", Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam
         << ", Diem Toan: " << fToan << ", Diem Van: " << fVan 
         << ", Diem Anh: " << fAnh << ", Tong: " << Tong() << endl;
}

// Tinh tong diem
float ThiSinh::Tong() const {
    return fToan + fVan + fAnh;
}

// Lay MSSV
string ThiSinh::GetMSSV() const {
    return MSSV;
}
