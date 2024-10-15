#ifndef DIEM_H
#define DIEM_H

class Diem {
private:
    double iHoanh;
    double iTung;

public:
    // Constructor mặc định
    Diem();
    
    // Constructor có tham số
    Diem(double hoanh, double tung);
    
    // Constructor sao chép
    Diem(const Diem &x);
    
    // Getter
    double GetTungDo() const;
    double GetHoanhDo() const;
    
    // Setter
    void SetTungDo(double tung);
    void SetHoanhDo(double hoanh);
    
    // Xuất tọa độ
    void Xuat() const;
    
    // Tịnh tiến tọa độ
    void TinhTien(double dX, double dY);
};

#endif
