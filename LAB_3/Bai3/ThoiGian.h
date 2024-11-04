// ThoiGian.h
#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    // Constructors
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);

    // Method to calculate total seconds
    int TinhGiay() const;

    // Method to recalculate hours, minutes, seconds from seconds
    void TinhLaiGio(int totalSeconds);

    // Operator overloads
    ThoiGian operator + (int Giay);
    ThoiGian operator - (int Giay);
    ThoiGian operator + (const ThoiGian& a);
    ThoiGian operator - (const ThoiGian& a);

    ThoiGian& operator++(); // Prefix increment
    ThoiGian operator++(int); // Postfix increment
    ThoiGian& operator--(); // Prefix decrement
    ThoiGian operator--(int); // Postfix decrement

    bool operator == (const ThoiGian& a) const;
    bool operator != (const ThoiGian& a) const;
    bool operator >= (const ThoiGian& a) const;
    bool operator <= (const ThoiGian& a) const;
    bool operator > (const ThoiGian& a) const;
    bool operator < (const ThoiGian& a) const;

    friend std::istream& operator>>(std::istream& in, ThoiGian& tg);
    friend std::ostream& operator<<(std::ostream& out, const ThoiGian& tg);
};

#endif
