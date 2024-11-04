#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <bits/stdc++.h>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;


    bool isLeapYear(int year) const;


    int getDaysInMonth(int month, int year) const;


    bool isValidDate(int ngay, int thang, int nam) const;

public:

    NgayThangNam();

    NgayThangNam(int Nam, int Thang, int Ngay);

    int TinhNgay() const;

    void TinhLaiNgay(int soNgay);

    NgayThangNam operator+(int ngay) const;

    NgayThangNam operator-(int ngay) const;

    int operator-(const NgayThangNam& other) const;

    NgayThangNam& operator++();  
    NgayThangNam operator++(int); 


    NgayThangNam& operator--();  
    NgayThangNam operator--(int); 


    bool operator==(const NgayThangNam& other) const;

    bool operator!=(const NgayThangNam& other) const;

    bool operator>=(const NgayThangNam& other) const;

    bool operator<=(const NgayThangNam& other) const;

    bool operator>(const NgayThangNam& other) const;

    bool operator<(const NgayThangNam& other) const;

    friend std::istream& operator>>(std::istream& is, NgayThangNam& date);

    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& date);
};

#endif
