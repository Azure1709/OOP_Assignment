#include <iostream>
#include "NgayThangNam.h"

int main() {
    NgayThangNam date1, date2;

    std::cout << "Nhap ngay, thang, nam cho date1 (ngay/thang/nam): ";
    std::cin >> date1; 
    std::cout << "Nhap ngay, thang, nam cho date2 (ngay/thang/nam): ";
    std::cin >> date2; 

    std::cout << "Date1: " << date1 << std::endl; 
    std::cout << "Date2: " << date2 << std::endl; 
    
    // So sánh hai ngày
    if (date1 == date2) {
        std::cout << "Hai ngay bang nhau." << std::endl;
    } else if (date1 > date2) {
        std::cout << "Date1 lon hon date2." << std::endl;
    } else {
        std::cout << "Date1 nho hon date2." << std::endl;
    }

    // Cong ngay
    int addDays;
    std::cout << "Nhap so ngay de cong cho date1: ";
    std::cin >> addDays;
    NgayThangNam date3 = date1 + addDays;
    std::cout << "Date1 + " << addDays << ": " << date3 << std::endl;

    // Tru ngay
    int subDays;
    std::cout << "Nhap so ngay de tru cho date1: ";
    std::cin >> subDays;
    NgayThangNam date4 = date1 - subDays;
    std::cout << "Date1 - " << subDays << ": " << date4 << std::endl;

    // Tinh so ngay giua hai ngay
    int daysBetween = date1 - date2;
    std::cout << "So ngay giua date1 va date2: " << daysBetween << std::endl;

    return 0;
}
