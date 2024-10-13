/*
Giả sử lớp PhanSo đã được khai báo.
a. Cài đặt toán tử > như khai báo cho lớp PhanSo
b. Hãy xây dựng lớp DSPhanSo để lưu trữ một
mảng các phân số cho phép thực hiện các thao
tác sau:
▪ Nhập giá trị cho các phân số trong mảng
▪ Tìm phân số có giá trị lớn nhất.
▪ Tính tổng các phân số trong mảng
c. Hãy viết chương trình để nhập một mảng
gồm n phân số (n do người dùng nhập). Sau đó
tìm và in ra màn hình phân số có giá trị lớn nhất.
*/

#include <bits/stdc++.h>
using namespace std;

class PhanSo {
    int tu, mau;
    friend class ArrayPS;

    public:
        PhanSo() {
            tu = 0;
            mau = 1;
        }

        void rutGon() {
            int ucln = __gcd(tu, mau);
            tu /= ucln;
            mau /= ucln;
            if (mau < 0) {
                tu = -tu;
                mau = -mau;
            }
        }

        PhanSo(int tu, int mau) {
            this->tu = tu;
            this->mau = mau;
            rutGon();
        }

        ~PhanSo() {}

        void Xuat() {
            if (mau == 1 or tu == 0) cout << tu << " ";
            else
                cout << tu << "/" << mau << " ";
        }
};
//------------------------------------------------------------------------------
class ArrayPS {
    PhanSo *a;
    int n;

    public:
        ArrayPS() {
            a = NULL;
            n = 0;
        }
        ~ArrayPS() {
            delete []a;
        }

        static bool cmp(const PhanSo &x, const PhanSo &y) {
            return x.tu * y.mau < y.tu * x.mau;
        }

        void Nhap(int n);
        void Xuat();
        void DayRandom(int n);
        PhanSo PSLonNhat();
        void demTuLaSNT();
        void DaysoTang();
};

void ArrayPS::Nhap(int n) {
    this->n = n;
    if (a != NULL) delete []a;
    a = new PhanSo[n];
    for (int i = 0, tu, mau; i < n; i++) {
        do {
            cout << "Nhap phan so thu " << i + 1 << ": \n";
            cout << "Tu so: ";
            cin >> tu;
            cout << "Mau so: "; 
            cin >> mau;
            if (mau == 0) cout << "Phan so khong hop le.\n";
        } while (mau == 0);
        a[i] = PhanSo(tu, mau);
    }
}

void ArrayPS::Xuat() {
    if (a == NULL) {
        cout << "Day rong!" << '\n';
        return;
    }
    cout << "Danh sach phan so: ";
    for (int i = 0; i < n; i++) {
        a[i].Xuat();
    }
    cout << '\n';
}

void ArrayPS::DayRandom(int n) {
    this->n = n;
    if (a != NULL) delete []a;
    a = new PhanSo[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int tu = rand() % 100 - 50;  // Tử số trong khoảng [-50, 50]
        int mau = rand() % 49 + 1;   // Mẫu số trong khoảng [1, 50]
        a[i] = PhanSo(tu, mau);
    }
}

PhanSo ArrayPS::PSLonNhat() {
    PhanSo max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].tu * max.mau > max.tu * a[i].mau) {
            max = a[i];
        }
    }
    return max;
}

void ArrayPS::demTuLaSNT() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int tu = abs(a[i].tu);  // Lấy trị tuyệt đối của tử số
        bool isPrime = true;
        if (tu < 2) isPrime = false;
        for (int j = 2; j * j <= tu; j++) {
            if (tu % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) count++;
    }
    cout << "So phan so co tu la so nguyen to: " << count << '\n';
}

void ArrayPS::DaysoTang() {
    sort(a, a + n, cmp);
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    ArrayPS a;
    a.Nhap(n);
    
    cout << "\n-- Danh sach cac phan so --" << '\n';
    a.Xuat();

    PhanSo maxPS = a.PSLonNhat();
    cout << "\nPhan so lon nhat: ";
    maxPS.Xuat();
    cout << '\n';

    a.demTuLaSNT();

    a.DaysoTang();
    cout << "\nDanh sach phan so sau khi sap xep tang dan: " << '\n';
    a.Xuat();

    // Tạo dãy số ngẫu nhiên
    cout << "\n-- Tao day phan so ngau nhien --\n";
    a.DayRandom(n);
    a.Xuat();
    cout << "Phan so lon nhat: "; a.PSLonNhat().Xuat(); cout << '\n';
    a.demTuLaSNT();
    a.DaysoTang();
    cout << "\nDanh sach sau khi sap xep day ngau nhien: \n";
    a.Xuat();

    return 0;
}
