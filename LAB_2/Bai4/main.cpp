#include <iostream>
#include "ThiSinh.h"
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    ThiSinh* ds = new ThiSinh[n];

    // Nhap thong tin cho n thi sinh
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thi sinh " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\nThi sinh co tong diem lon hon 15:\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].Tong() > 15) {
            ds[i].Xuat();
        }
    }

    // Tim thi sinh co diem cao nhat
    float maxScore = 0;
    int indexMax = -1;

    for (int i = 0; i < n; i++) {
        if (ds[i].Tong() > maxScore) {
            maxScore = ds[i].Tong();
            indexMax = i;
        }
    }

    // In ra thi sinh co diem cao nhat
    if (indexMax != -1) {
        cout << "\nThi sinh co diem cao nhat:\n";
        ds[indexMax].Xuat();
    }

    delete[] ds;
    return 0;
}
