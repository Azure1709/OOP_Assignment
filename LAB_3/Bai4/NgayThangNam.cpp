#include "NgayThangNam.h"

// Khoi tao mac dinh
NgayThangNam::NgayThangNam() : iNam(0), iThang(1), iNgay(1) {}

// Khoi tao co tham so
NgayThangNam::NgayThangNam(int nam, int thang, int ngay) : iNam(nam), iThang(thang), iNgay(ngay) {}

// Tinh tong so ngay
int NgayThangNam::TinhNgay() {
    int days = 0; // Bien dem so ngay
    for (int m = 1; m < iThang; m++) { // Duyet qua cac thang
        if (m == 2) { // Thang 2
            days += (iNam % 4 == 0 && (iNam % 100 != 0 || iNam % 400 == 0)) ? 29 : 28; // Thang 2 co 28 hoac 29 ngay
        } else if (m == 4 || m == 6 || m == 9 || m == 11) { // Thang co 30 ngay
            days += 30;
        } else { // Thang co 31 ngay
            days += 31;
        }
    }
    days += iNgay; // Cong them so ngay
    return days; // Tra ve tong so ngay
}

// Phuong thuc toan tu +
NgayThangNam NgayThangNam::operator+(int ngay) {
    NgayThangNam temp = *this; // Tao bien tam
    temp.iNgay += ngay; // Cong so ngay

    // Dieu chinh cho so ngay trong thang
    while (temp.iNgay > 30) { // Chua xu ly chinh xac so ngay trong thang
        temp.iNgay -= 30;
        temp.iThang++;
        if (temp.iThang > 12) {
            temp.iThang = 1; // Qua thang 12 thi tang nam
            temp.iNam++;
        }
    }
    return temp; // Tra ve ket qua
}

// Phuong thuc toan tu -
NgayThangNam NgayThangNam::operator-(int ngay) {
    NgayThangNam temp = *this; // Tao bien tam
    temp.iNgay -= ngay; // Tru so ngay

    // Dieu chinh cho so ngay trong thang
    while (temp.iNgay <= 0) {
        temp.iNgay += 30; // Chua xu ly chinh xac so ngay trong thang
        temp.iThang--;
        if (temp.iThang < 1) {
            temp.iThang = 12; // Truot thang 1 thi giam nam
            temp.iNam--;
        }
    }
    return temp; // Tra ve ket qua
}

// Phuong thuc toan tu -
int NgayThangNam::operator - (NgayThangNam a) {
    return this->TinhNgay() - a.TinhNgay(); // Tinh so ngay giua hai ngay
}

// Phuong thuc toan tu ++
NgayThangNam NgayThangNam::operator ++() {
    return *this + 1; // Giai phap cho toan tu ++
}

// Phuong thuc toan tu --
NgayThangNam NgayThangNam::operator --() {
    return *this - 1; // Giai phap cho toan tu --
}

// Phuong thuc toan tu ==
bool NgayThangNam::operator == (NgayThangNam a) {
    return (iNam == a.iNam && iThang == a.iThang && iNgay == a.iNgay); // So sanh hai ngay
}

// Phuong thuc toan tu !=
bool NgayThangNam::operator != (NgayThangNam a) {
    return !(*this == a); // Tra ve phan nguoc
}

// Phuong thuc toan tu >=
bool NgayThangNam::operator >= (NgayThangNam a) {
    return TinhNgay() >= a.TinhNgay(); // So sanh
}

// Phuong thuc toan tu <=
bool NgayThangNam::operator <= (NgayThangNam a) {
    return TinhNgay() <= a.TinhNgay(); // So sanh
}

// Phuong thuc toan tu >
bool NgayThangNam::operator > (NgayThangNam a) {
    return TinhNgay() > a.TinhNgay(); // So sanh
}

// Phuong thuc toan tu <
bool NgayThangNam::operator < (NgayThangNam a) {
    return TinhNgay() < a.TinhNgay(); // So sanh
}

// Ham friend nhap
std::istream& operator >> (std::istream& in, NgayThangNam& date) {
    in >> date.iNam >> date.iThang >> date.iNgay; // Nhap nam, thang, ngay
    return in; // Tra ve
}

// Ham friend xuat
std::ostream& operator << (std::ostream& out, const NgayThangNam& date) {
    out << date.iNgay << "/" << date.iThang << "/" << date.iNam; // Xuat ngay/thang/nam
    return out; // Tra ve
}
