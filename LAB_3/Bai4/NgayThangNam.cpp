#include "NgayThangNam.h"


NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(0) {}


NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) : iNgay(Ngay), iThang(Thang), iNam(Nam) {}


bool NgayThangNam::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int NgayThangNam::getDaysInMonth(int month, int year) const {
    switch (month) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 31;
    }
}

int NgayThangNam::TinhNgay() const {
    int totalDays = iNgay;
    for (int y = 0; y < iNam; ++y) totalDays += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < iThang; ++m) totalDays += getDaysInMonth(m, iNam);
    return totalDays;
}

void NgayThangNam::TinhLaiNgay(int soNgay) {
    iNam = 0;
    while (soNgay >= (isLeapYear(iNam) ? 366 : 365)) soNgay -= isLeapYear(iNam++) ? 366 : 365;
    iThang = 1;
    while (soNgay >= getDaysInMonth(iThang, iNam)) soNgay -= getDaysInMonth(iThang++, iNam);
    iNgay = soNgay + 1;
}


NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam result = *this;
    result.TinhLaiNgay(TinhNgay() + ngay);
    return result;
}


NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam result = *this;
    result.TinhLaiNgay(TinhNgay() - ngay);
    return result;
}


int NgayThangNam::operator-(const NgayThangNam& other) const {
    return TinhNgay() - other.TinhNgay();
}


NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

NgayThangNam NgayThangNam::operator++(int) {
    NgayThangNam temp = *this;
    ++(*this);
    return temp;
}


NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}


NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp = *this;
    --(*this);
    return temp;
}


bool NgayThangNam::operator==(const NgayThangNam& other) const {
    return iNgay == other.iNgay && iThang == other.iThang && iNam == other.iNam;
}

bool NgayThangNam::operator!=(const NgayThangNam& other) const {
    return !(*this == other);
}


bool NgayThangNam::operator>=(const NgayThangNam& other) const { return TinhNgay() >= other.TinhNgay(); }

bool NgayThangNam::operator<=(const NgayThangNam& other) const { return TinhNgay() <= other.TinhNgay(); }

bool NgayThangNam::operator>(const NgayThangNam& other) const { return TinhNgay() > other.TinhNgay(); }

bool NgayThangNam::operator<(const NgayThangNam& other) const { return TinhNgay() < other.TinhNgay(); }


std::istream& operator>>(std::istream& is, NgayThangNam& date) {
    std::cout << "Nhap ngay: "; 
    is >> date.iNgay;
    std::cout << "Nhap thang: "; 
    is >> date.iThang;
    std::cout << "Nhap nam: "; 
    is >> date.iNam;
    return is;
}

std::ostream& operator<<(std::ostream& os, const NgayThangNam& date) {
    os << date.iNgay << "/" << date.iThang << "/" << date.iNam;
    return os;
}
