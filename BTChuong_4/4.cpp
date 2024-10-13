/*
Xét đa thức theo biến x (đa thức một biến) bậc n có dạng như sau:
P(X) = a1xn + a2xn-1 + a3xn-2 + … + aj
Trong đó: n là bậc của đa thức. a1, a2, a3,…, aj là các hệ số tương ứng với
từng bậc của đa thức.
a. Xây dựng lớp DaThuc biểu diễn khái niệm đa thức với các thao tác sau:
- Khởi tạo một đa thức có bậc bằng 0 hoặc bậc n.
- Tính giá trị của đa thức khi biết giá trị của x
- Nhập đa thức
- Xuất đa thức
- Cộng hai đa thức
- Trừ hai đa thức
b. Viết chương trình cho phép người dùng nhập vào hai đa thức rồi xuất các
đa thức ra màn hình. Sau đó tính tổng hai đa thức và xuất kết quả ra màn
hình.
*/

#include <bits/stdc++.h>
using namespace std;

class DaThuc {
private:
    int bac;               
    vector<float> heSo;   

public:
    // 1. Hàm khởi tạo đa thức bậc 0 (hằng số)
    DaThuc() : bac(0), heSo(1, 0) {}

    // 2. Hàm khởi tạo đa thức bậc n
    DaThuc(int n) : bac(n), heSo(n + 1, 0) {}

    // 3. Nhập đa thức
    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        // Thay đổi kích thước mảng hệ số cho phù hợp với bậc đa thức
        heSo.resize(bac + 1); 
        for (int i = bac; i >= 0; i--) {
            cout << "Nhap he so bac " << i << ": ";
            cin >> heSo[i];
        }
    }

    // 4. Xuất đa thức ra màn hình
    void xuat() const {
        for (int i = bac; i >= 0; i--) {
            if (heSo[i] != 0) {
                cout << heSo[i] << "x^" << i;
                if (i > 0) cout << " + ";
            }
        }
        cout << endl;
    }

    // 5. Tính giá trị của đa thức khi biết x
    float giaTri(float x) const {
        float ketQua = 0;
        for (int i = bac; i >= 0; i--) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }

    // 6. Cộng hai đa thức
    DaThuc cong(const DaThuc &other) const {
        int maxBac = max(bac, other.bac);
        DaThuc ketQua(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            if (i <= bac) ketQua.heSo[i] += heSo[i];
            if (i <= other.bac) ketQua.heSo[i] += other.heSo[i];
        }

        // Xử lý bậc thực tế của đa thức kết quả
        while (ketQua.bac > 0 && ketQua.heSo[ketQua.bac] == 0) {
            ketQua.bac--;
        }

        return ketQua;
    }

    // 7. Trừ hai đa thức
    DaThuc tru(const DaThuc &other) const {
        int maxBac = max(bac, other.bac);
        DaThuc ketQua(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            if (i <= bac) ketQua.heSo[i] += heSo[i];
            if (i <= other.bac) ketQua.heSo[i] -= other.heSo[i];
        }

        // Xử lý bậc thực tế của đa thức kết quả
        while (ketQua.bac > 0 && ketQua.heSo[ketQua.bac] == 0) {
            ketQua.bac--;
        }

        return ketQua;
    }
};

int main() {
    // Nhập hai đa thức
    DaThuc dt1, dt2;
    cout << "Nhap da thuc thu nhat:" << endl;
    dt1.nhap();
    cout << "Nhap da thuc thu hai:" << endl;
    dt2.nhap();

    // Xuất hai đa thức
    cout << "Da thuc thu nhat: ";
    dt1.xuat();
    cout << "Da thuc thu hai: ";
    dt2.xuat();

    // Tính tổng hai đa thức
    DaThuc tong = dt1.cong(dt2);
    cout << "Tong hai da thuc: ";
    tong.xuat();

    // Tính hiệu hai đa thức
    DaThuc hieu = dt1.tru(dt2);
    cout << "Hieu hai da thuc: ";
    hieu.xuat();

    return 0;
}
