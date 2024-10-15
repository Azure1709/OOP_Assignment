#include <iostream>
#include "Diem.h"

using namespace std;

// Constructor mặc định
Diem::Diem() : iHoanh(0), iTung(0) {}

// Constructor có tham số
Diem::Diem(double hoanh, double tung) : iHoanh(hoanh), iTung(tung) {}

// Constructor sao chép
Diem::Diem(const Diem &x) {
    iHoanh = x.iHoanh;
    iTung = x.iTung;
}

// Getter
double Diem::GetTungDo() const {
    return iTung;
}

double Diem::GetHoanhDo() const {
    return iHoanh;
}

// Setter
void Diem::SetTungDo(double tung) {
    iTung = tung;
}

void Diem::SetHoanhDo(double hoanh) {
    iHoanh = hoanh;
}

// Xuất tọa độ
void Diem::Xuat() const {
    cout << "(" << iHoanh << ", " << iTung << ")" << endl;
}

// Tịnh tiến tọa độ
void Diem::TinhTien(double dX, double dY) {
    iHoanh += dX;
    iTung += dY;
}
