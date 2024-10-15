#include <iostream>
#include "Diem.h"

using namespace std;

int main() {
    double hoanh, tung;

    // Nhập tọa độ cho điểm A
    cout << "Nhap toa do diem A (hoanh, tung): ";
    cin >> hoanh >> tung;
    Diem A(hoanh, tung);  // Gọi constructor có tham số từ input người dùng

    // Nhập tọa độ cho điểm B
    cout << "Nhap toa do diem B (hoanh, tung): ";
    cin >> hoanh >> tung;
    Diem B(hoanh, tung);  // Gọi constructor có tham số từ input người dùng

    // Sao chép điểm B vào điểm C
    Diem C(B);  // Gọi constructor sao chép

    // Xuất tọa độ của các điểm
    cout << "Toa do diem A: ";
    A.Xuat();

    cout << "Toa do diem B: ";
    B.Xuat();

    cout << "Toa do diem C (sao chep tu diem B): ";
    C.Xuat();

    // Sử dụng setter để thay đổi tọa độ của A
    cout << "Nhap toa do moi cho diem A (hoanh, tung): ";
    cin >> hoanh >> tung;
    A.SetHoanhDo(hoanh);
    A.SetTungDo(tung);
    cout << "Toa do diem A sau khi set: ";
    A.Xuat();

    // Nhập giá trị tịnh tiến cho điểm B
    double dX, dY;
    cout << "Nhap gia tri tinh tien cho diem B (dX, dY): ";
    cin >> dX >> dY;
    B.TinhTien(dX, dY);
    cout << "Toa do diem B sau khi tinh tien: ";
    B.Xuat();

    return 0;
}
