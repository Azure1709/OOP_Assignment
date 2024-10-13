/*
Cài đặt lớp ArrayPS cho phép lưu trữ và thực
hiện các thao tác trên mảng các phân số:
1. Nhập các phân số
2. Xuất danh sách các phân số
3. Tạo n phân số ngẫu nhiên
4. Tìm phân số có giá trị lớn nhất
5. Đếm xem có bao nhiêu phân số có tử là số nguyên tố
6. Sắp xếp các phân số trong mang theo thứ tự tăng
dần.
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
            return x.tu*y.mau < y.tu*x.mau;
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
    for (int i=0, tu, mau; i<n; i++) {
        do {
            cout << "Nhap phan so thu " << i+1 << ": \n";
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
        cout << "Day rong!";
        return;
    }
    cout << "Day phan so: ";
    for (int i=0; i<n; i++) {
        a[i].Xuat();
    }
    cout << '\n';
}

void ArrayPS::DayRandom(int n) {
    this->n = n;
    if (a != NULL) delete []a;
    a = new PhanSo[n];
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        a[i].tu = rand()%int(1e6);
        a[i].mau = rand()%int(1e6);
    }
}

PhanSo ArrayPS::PSLonNhat() {
    PhanSo max = a[0];
    for (int i=1; i<n; i++) if (a[i].tu*max.mau > max.tu*a[i].mau) max = a[i];
    return max;
}


void ArrayPS::demTuLaSNT() {
    int count = 0;
    for (int i=0; i<n; i++) {
        int tu = a[i].tu;
        bool check = true;
        if (tu < 2) check = false;
        for (int j=2; j<=sqrt(tu); j++) if (tu%j == 0) {
            check = false;
            break;
        }
        if (check) count++;
    }
    cout << "So phan so co tu la so nguyen to: " << count << '\n';
}

void ArrayPS::DaysoTang() {
    sort(a, a+n, cmp);
}

int main() {
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;

    ArrayPS a;
    a.Nhap(n);
    a.Xuat();
    cout << "Phan so lon nhat: "; a.PSLonNhat().Xuat(); cout << '\n';
    a.demTuLaSNT();
    a.DaysoTang();
    cout << "Day tang dan: \n_ ";
    a.Xuat();

    a.DayRandom(n);
    a.Xuat();
    cout << "Phan so lon nhat: "; a.PSLonNhat().Xuat(); cout << '\n';
    a.demTuLaSNT();
    a.DaysoTang();
    a.Xuat();
    
    return 0;
}
