/*
Xét đa thức theo biến x (một biến) bậc n có dạng như sau:
P(X) = a1xn + a2xn-1 + a3xn-2 + … + aj
Trong đó: n là bậc của đa thức. a1, a2, a3,…, aj là các hệ số tương
ứng với từng bậc của đa thức.
a. Xây dựng lớp DaThuc biểu diễn khái niệm đa thức với các thao
tác như sau:
- Khởi tạo đa thức có bậc bằng 0
- Khởi tạo đa thức bậc n bất kỳ.
- Tính giá trị đa thức khi biết giá trị của biến x
- Định nghĩa các toán tử: >>, <<, +, -
b. Viết chương trình minh họa các chức năng tương ứng.
*/

#include <bits/stdc++.h>
using namespace std;

class DaThuc {
    int n; // Bậc của đa thức
    vector<int> heso; // Hệ số của các bậc từ bậc cao nhất đến bậc 0

public:
    DaThuc() {
        n = 0;
        heso.push_back(0);
    }

    DaThuc(int n) {
        this->n = n;
        heso.resize(n + 1); // Đa thức có n+1 hệ số (từ bậc n đến bậc 0)
    }

    // Định nghĩa toán tử nhập >>
    friend istream& operator>>(istream& is, DaThuc& dt) {
        cout << "Nhap he so cua da thuc bac " << dt.n << ":\n";
        for (int i = dt.n; i >= 0; i--) {
            cout << "He so bac " << i << ": ";
            is >> dt.heso[i];
        }
        return is;
    }

    // Định nghĩa toán tử xuất <<
    friend ostream& operator<<(ostream& os, const DaThuc& dt) {
        for (int i = dt.n; i >= 0; i--) {
            if (dt.heso[i] != 0) {
                if (i == dt.n) os << dt.heso[i] << "x^" << i;
                else {
                    if (dt.heso[i] > 0) os << " + " << dt.heso[i] << "x^" << i;
                    else os << " - " << -dt.heso[i] << "x^" << i;
                }
            }
        }
        return os;
    }

    // Tính giá trị của đa thức với giá trị x
    int tinhGiaTri(int x) {
        int value = 0;
        for (int i = 0; i <= n; i++) {
            value += heso[i] * pow(x, i);
        }
        return value;
    }

    // Định nghĩa toán tử +
    DaThuc operator+(const DaThuc& dt) {
        int maxBac = max(n, dt.n);
        DaThuc result(maxBac);

        // Cộng các hệ số tương ứng
        for (int i = 0; i <= maxBac; i++) {
            int hs1 = (i <= n) ? heso[i] : 0;
            int hs2 = (i <= dt.n) ? dt.heso[i] : 0;
            result.heso[i] = hs1 + hs2;
        }

        return result;
    }

    // Định nghĩa toán tử -
    DaThuc operator-(const DaThuc& dt) {
        int maxBac = max(n, dt.n);
        DaThuc result(maxBac);

        // Trừ các hệ số tương ứng
        for (int i = 0; i <= maxBac; i++) {
            int hs1 = (i <= n) ? heso[i] : 0;
            int hs2 = (i <= dt.n) ? dt.heso[i] : 0;
            result.heso[i] = hs1 - hs2;
        }

        return result;
    }
};

// Chương trình minh họa
int main() {
    // Nhập đa thức thứ nhất
    int bac1;
    cout << "Nhap bac cua da thuc thu nhat: ";
    cin >> bac1;
    DaThuc dt1(bac1);
    cin >> dt1;

    // Nhập đa thức thứ hai
    int bac2;
    cout << "Nhap bac cua da thuc thu hai: ";
    cin >> bac2;
    DaThuc dt2(bac2);
    cin >> dt2;

    // Hiển thị hai đa thức
    cout << "Da thuc thu nhat: " << dt1 << endl;
    cout << "Da thuc thu hai: " << dt2 << endl;

    // Cộng hai đa thức
    DaThuc tong = dt1 + dt2;
    cout << "Tong hai da thuc: " << tong << endl;

    // Trừ hai đa thức
    DaThuc hieu = dt1 - dt2;
    cout << "Hieu hai da thuc: " << hieu << endl;

    // Tính giá trị của đa thức với giá trị x
    int x;
    cout << "Nhap gia tri cua x de tinh gia tri cua da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat khi x = " << x << " la: " << dt1.tinhGiaTri(x) << endl;
    cout << "Gia tri cua da thuc thu nhat khi x = " << x << " la: " << dt2.tinhGiaTri(x) << endl;
    
    return 0;
}
