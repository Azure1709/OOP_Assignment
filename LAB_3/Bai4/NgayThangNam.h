#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <iostream>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    NgayThangNam();
    NgayThangNam(int nam, int thang, int ngay);
    int TinhNgay();
    NgayThangNam operator+(int ngay);
    NgayThangNam operator-(int ngay);
    int operator-(NgayThangNam a);
    NgayThangNam operator++();
    NgayThangNam operator--();
    bool operator == (NgayThangNam a);
    bool operator != (NgayThangNam a);
    bool operator >= (NgayThangNam a);
    bool operator <= (NgayThangNam a);
    bool operator > (NgayThangNam a);
    bool operator < (NgayThangNam a);
    friend std::istream& operator>>(std::istream& in, NgayThangNam& date);
    friend std::ostream& operator<<(std::ostream& out, const NgayThangNam& date);
};

#endif // NGAYTHANGNAM_H
