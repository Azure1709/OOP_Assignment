// ThoiGian.cpp
#include "ThoiGian.h"

// Constructors
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {}

// Calculate total seconds
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Recalculate hours, minutes, seconds from total seconds
void ThoiGian::TinhLaiGio(int totalSeconds) {
    iGio = totalSeconds / 3600;
    iPhut = (totalSeconds % 3600) / 60;
    iGiay = totalSeconds % 60;
}

// Operator overloads for +, -
ThoiGian ThoiGian::operator+(int Giay) {
    int totalSeconds = TinhGiay() + Giay;
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

ThoiGian ThoiGian::operator-(int Giay) {
    int totalSeconds = TinhGiay() - Giay;
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

ThoiGian ThoiGian::operator+(const ThoiGian& a) {
    int totalSeconds = TinhGiay() + a.TinhGiay();
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

ThoiGian ThoiGian::operator-(const ThoiGian& a) {
    int totalSeconds = TinhGiay() - a.TinhGiay();
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

// Increment and decrement operators
ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

// Comparison operators
bool ThoiGian::operator == (const ThoiGian& a) const {
    return TinhGiay() == a.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& a) const {
    return TinhGiay() != a.TinhGiay();
}

bool ThoiGian::operator >= (const ThoiGian& a) const {
    return TinhGiay() >= a.TinhGiay();
}

bool ThoiGian::operator <= (const ThoiGian& a) const {
    return TinhGiay() <= a.TinhGiay();
}

bool ThoiGian::operator > (const ThoiGian& a) const {
    return TinhGiay() > a.TinhGiay();
}

bool ThoiGian::operator < (const ThoiGian& a) const {
    return TinhGiay() < a.TinhGiay();
}

// Input and output operators
std::istream& operator>>(std::istream& in, ThoiGian& tg) {
    std::cout << "Nhap gio: ";
    in >> tg.iGio;
    std::cout << "Nhap phut: ";
    in >> tg.iPhut;
    std::cout << "Nhap giay: ";
    in >> tg.iGiay;
    return in;
}

std::ostream& operator<<(std::ostream& out, const ThoiGian& tg) {
    out << tg.iGio << " gio, " << tg.iPhut << " phut, " << tg.iGiay << " giay";
    return out;
}
