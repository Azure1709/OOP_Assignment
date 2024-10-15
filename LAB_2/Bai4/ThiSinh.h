#ifndef THISINH_H
#define THISINH_H

#include <string>
using namespace std;

class ThiSinh {
private:
    string Ten;
    string MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;

public:
    // Nhap thong tin thi sinh
    void Nhap();

    // Xuat thong tin thi sinh
    void Xuat() const;

    // Tinh tong diem
    float Tong() const;

    // Lay MSSV
    string GetMSSV() const;
};

#endif // THISINH_H
