#include <iostream>
#include "NgayThangNam.h"

int main() {
    NgayThangNam date1, date2; // Khai bao hai bien NgayThangNam

    std::cout << "Nhap ngay, thang, nam cho date1 (ngay/thang/nam): ";
    std::cin >> date1; // Nhap date1
    std::cout << "Nhap ngay, thang, nam cho date2 (ngay/thang/nam): ";
    std::cin >> date2; // Nhap date2

    std::cout << "Date1: " << date1 << std::endl; // Xuat date1
    std::cout << "Date2: " << date2 << std::endl; // Xuat date2

    // So sanh hai ngay
    if (date1 == date2) {
        std::cout << "Hai ngay bang nhau." << std::endl; // Bang nhau
    } else if (date1 > date2) {
        std::cout << "Date1 lon hon date2." << std::endl; // Date1 lon hon
    } else {
        std::cout << "Date1 nho hon date2." << std::endl; // Date1 nho hon
    }

    // Cong ngay
    NgayThangNam date3 = date1 + 10; // Cong 10 ngay
    std::cout << "Date1 + 10: " << date3 << std::endl; // Xuat ket qua

    // Tru ngay
    NgayThangNam date4 = date1 - 5; // Tru 5 ngay
    std::cout << "Date1 - 5: " << date4 << std::endl; // Xuat ket qua

    // Tinh so ngay giua hai ngay
    int daysBetween = date1 - date2; // Tinh so ngay giua hai ngay
    std::cout << "So ngay giua date1 va date2: " << daysBetween << std::endl; // Xuat ket qua

    return 0; // Ket thuc
}
