#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

class PhanSo {
private:
    int iTu;
    int iMau;

    void simplify();

public:
    PhanSo();
    PhanSo(int Tu, int Mau);

    PhanSo operator+(const PhanSo& other);
    PhanSo operator-(const PhanSo& other);
    PhanSo operator*(const PhanSo& other);
    PhanSo operator/(const PhanSo& other);

    bool operator==(const PhanSo& other) const;
    bool operator!=(const PhanSo& other) const;
    bool operator>=(const PhanSo& other) const;
    bool operator<=(const PhanSo& other) const;
    bool operator>(const PhanSo& other) const;
    bool operator<(const PhanSo& other) const;

    friend std::istream& operator>>(std::istream& in, PhanSo& ps);
    friend std::ostream& operator<<(std::ostream& out, const PhanSo& ps);
};

#endif
