#include <bits/stdc++.h>
#include "NgayThangNam.h"

int main() {
    NgayThangNam ngay1, ngay2;

    std::cout << "Nhap ngay thang nam date1:" << '\n';
    std::cin >> ngay1;
    std::cout << "Nhap ngay thang nam date2:" << '\n';
    std::cin >> ngay2;

    std::cout << "Ngay thu nhat: " << ngay1 << '\n';
    std::cout << "Ngay thu hai: " << ngay2 << '\n';


    NgayThangNam ketQuaCong = ngay1 + 15;
    std::cout << "Ngay thu nhat sau khi cong 15 ngay: " << ketQuaCong << '\n';

    NgayThangNam ketQuaTru = ngay2 - 20;
    std::cout << "Ngay thu hai sau khi tru 20 ngay: " << ketQuaTru << '\n';

    int khoangCach = abs(ngay1 - ngay2);
    std::cout << "Khoang cach giua hai ngay la: " << khoangCach << " ngay" << '\n';

    exit(0);
}
