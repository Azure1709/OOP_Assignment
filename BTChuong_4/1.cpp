/*
Khai báo và định nghĩa lớp mảng một chiều (lớp cArray) 
để lưu trữ danh sách các số nguyên, hỗ trợ các thao tác sau:
 1. Nhập dãy số nguyên gồm n phần tử.
 2. Xuất dãy số nguyên của mảng.
 3. Tạo dãy gồm n số nguyên ngẫu nhiên.
 4. Đếm số lần xuất hiện của x trong mảng.
 5. Kiểm tra dãy số nguyên có tăng dần hay không.
 6. Tìm phần tử lẻ nhỏ nhất trong dãy số nguyên.
 7. Sắp xếp các số nguyên trong dãy tăng dần.
*/

#include<bits/stdc++.h>
using namespace std;

class cArray {
private:
    vector<int> arr; // Mảng lưu trữ danh sách số nguyên

public:
    // 1. Nhập dãy số nguyên gồm n phần tử
    void nhapMang(int n) {
        arr.resize(n);
        cout << "So phan tu: " << n << "\n";
        cout << "Nhap day: ";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    }

    // 2. Xuất dãy số nguyên của mảng
    void xuatMang() const {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 3. Tạo dãy gồm n số nguyên ngẫu nhiên
    void taoNgauNhien(int n) {
        arr.resize(n);
        srand(static_cast<unsigned>(time(0))); // Khởi tạo seed cho random
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 100; // Số ngẫu nhiên trong khoảng 0-99
        }
    }

    // 4. Đếm số lần xuất hiện của x trong mảng
    int demSoLanXuatHien(int x) const {
        int count = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == x) {
                count++;
            }
        }
        return count;
    }

    // 5. Kiểm tra dãy số nguyên có tăng dần hay không
    bool kiemTraTangDan() const {
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // 6. Tìm phần tử lẻ nhỏ nhất trong dãy số nguyên
    int timLeNhoNhat() const {
        int leNhoNhat = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] % 2 != 0) { // Phần tử lẻ
                if (leNhoNhat == -1 || arr[i] < leNhoNhat) {
                    leNhoNhat = arr[i];
                }
            }
        }
        return leNhoNhat;
    }

    // 7. Sắp xếp các số nguyên trong dãy tăng dần
    void sapXepTangDan() {
        sort(arr.begin(), arr.end());
    }
};

int main() {
    cArray mang;
    int n;
    
    cout << "So luong phan tu: ";
    cin >> n;
    
    mang.nhapMang(n);
    
    cout << "Day: ";
    mang.xuatMang();
    
    mang.taoNgauNhien(n);
    cout << "Day ngau nhien: ";
    mang.xuatMang();
    
    int x;
    cout << "So can dem trong mang: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << mang.demSoLanXuatHien(x) << endl;
 
    cout << "Day co tang dan ? " << (mang.kiemTraTangDan() ? "Yes" : "No") << endl;
    
 
    int leNhoNhat = mang.timLeNhoNhat();
    if (leNhoNhat != -1) {
        cout << "Phan tu le nho nhat " << leNhoNhat << endl;
    } else {
        cout << "Khong co so le trong mang.\n";
    }
    
    // Sắp xếp mảng tăng dần
    mang.sapXepTangDan();
    cout << "Day sau khi sap xep: ";
    mang.xuatMang();
    
    return 0;
}
