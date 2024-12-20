#ifndef BAI1_H
#define BAI1_H

#include <iostream>
#include <iomanip>
#define ll long long
#include <string>
using namespace std;

class NhanVien {
protected:
    string maSo;
    string ten;
    ll luongCoBan;

public:
    NhanVien(const string &ms, const string &t, ll lcb) 
            : maSo(ms), ten(t), luongCoBan(lcb) {}
    virtual double TienThuong() const = 0; 
    virtual void Xuat() const; 
};

class QuanLy : public NhanVien {
private:
    double tyLeThuong;

public:
    QuanLy(const string &ms, const string &t, ll lcb, double tlt)
        : NhanVien(ms, t, lcb), tyLeThuong(tlt) {}

    double TienThuong() const override {
        return luongCoBan * tyLeThuong;
    }

    void Xuat() const override;
};

class KySu : public NhanVien {
private:
    int soGioLamThem;

public:
    KySu(const string &ms, const string &t, ll lcb, int sglm)
        : NhanVien(ms, t, lcb), soGioLamThem(sglm) {}

    double TienThuong() const override {
        return soGioLamThem * 100000; 
    }

    void Xuat() const override;
};

#endif
