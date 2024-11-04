#include "PhanSo.h"
#include <iostream>
#include <numeric>

PhanSo::PhanSo() : iTu(0), iMau(1) {}

PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    simplify();
}

void PhanSo::simplify() {
    int gcd = std::gcd(iTu, iMau);
    iTu /= gcd;
    iMau /= gcd;
    if (iMau < 0) {  // Ensure denominator is positive
        iTu = -iTu;
        iMau = -iMau;
    }
}

PhanSo PhanSo::operator+(const PhanSo& other) {
    return PhanSo(iTu * other.iMau + other.iTu * iMau, iMau * other.iMau);
}

PhanSo PhanSo::operator-(const PhanSo& other) {
    return PhanSo(iTu * other.iMau - other.iTu * iMau, iMau * other.iMau);
}

PhanSo PhanSo::operator*(const PhanSo& other) {
    return PhanSo(iTu * other.iTu, iMau * other.iMau);
}

PhanSo PhanSo::operator/(const PhanSo& other) {
    return PhanSo(iTu * other.iMau, iMau * other.iTu);
}

bool PhanSo::operator==(const PhanSo& other) const {
    return iTu * other.iMau == iMau * other.iTu;
}

bool PhanSo::operator!=(const PhanSo& other) const {
    return !(*this == other);
}

bool PhanSo::operator>=(const PhanSo& other) const {
    return iTu * other.iMau >= iMau * other.iTu;
}

bool PhanSo::operator<=(const PhanSo& other) const {
    return iTu * other.iMau <= iMau * other.iTu;
}

bool PhanSo::operator>(const PhanSo& other) const {
    return iTu * other.iMau > iMau * other.iTu;
}

bool PhanSo::operator<(const PhanSo& other) const {
    return iTu * other.iMau < iMau * other.iTu;
}

std::istream& operator>>(std::istream& in, PhanSo& ps) {
    in >> ps.iTu >> ps.iMau;
    ps.simplify();
    return in;
}

std::ostream& operator<<(std::ostream& out, const PhanSo& ps) {
    out << ps.iTu << "/" << ps.iMau;
    return out;
}
