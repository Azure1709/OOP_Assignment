/*
❖ Cài đặt lớp Đơn thức biểu diễn khái niệm đơn thức (P(x) = axb) 
cho phép thực hiện các yêu cầu sau:
1. Tạo lập đơn thức
2. Nhập thông tin cho đơn thức, thay đổi thông tin đơn thức
3. Xuất đơn thức ra màn hình
4. Tính giá trị của đơn thức khi biết x
5. Tính đạo hàm của đơn thức
6. Tính tổng hai đơn thức (hai đơn thức cùng bậc)
❖ Viết chương trình cho phép nhập vào 2 đơn thức, tính
tổng hai đơn thức và xuất kế quả ra màn hình.
*/
#include <bits/stdc++.h>
using namespace std;

class DonThuc {
private:
    float a; // Hệ số
    int b;   // Số mũ

public:
    // 1. Hàm tạo lập không tham số
    DonThuc() : a(0), b(0) {}

    // 2. Hàm tạo lập có tham số
    DonThuc(float heso, int somu) : a(heso), b(somu) {}

    // 3. Hàm nhập thông tin cho đơn thức
    void nhap() {
        cout << "Nhap he so a: ";
        cin >> a;
        cout << "Nhap so mu b: ";
        cin >> b;
    }

    // 4. Hàm thay đổi thông tin đơn thức
    void thayDoi(float heso, int somu) {
        a = heso;
        b = somu;
    }

    // 5. Hàm xuất đơn thức ra màn hình
    void xuat() const {
        cout << a << "x^" << b;
    }

    // 6. Hàm tính giá trị của đơn thức khi biết x
    float giaTri(float x) const {
        return a * pow(x, b);
    }

    // 7. Hàm tính đạo hàm của đơn thức
    DonThuc daoHam() const {
        if (b == 0) // Đạo hàm của hằng số bằng 0
            return DonThuc(0, 0);
        return DonThuc(a * b, b - 1);
    }

    // 8. Hàm tính tổng hai đơn thức (chỉ cộng khi cùng bậc)
    DonThuc tong(const DonThuc &other) const {
        if (b == other.b) {
            return DonThuc(a + other.a, b);
        } else {
            cout << "Hai don thuc khong cung bac, khong the thuc hien phep tinh" << endl;
            return DonThuc(0, 0);
        }
    }
};

int main() {
    // Nhập hai đơn thức
    DonThuc dt1, dt2;
    cout << "Nhap don thuc thu nhat:" << endl ;
    dt1.nhap();
    cout << endl;
    cout << "Nhap don thuc thu hai:" << endl;
    dt2.nhap();

    // Xuất hai đơn thức
    cout << "Don thuc thu nhat: ";
    dt1.xuat();
    cout << " " << endl;
    cout << "Don thuc thu hai: ";
    dt2.xuat();
    cout << endl;

    // Tính tổng hai đơn thức
    DonThuc tong = dt1.tong(dt2);
    cout << "Tong hai don thuc: ";
    tong.xuat();
    cout << endl;

    return 0;
}
