// Cài đặt lớp cArray để biểu diễn mảng một chiều các
// số nguyên cho phép thực hiện các yêu cầu sau:
// ▪ Tạo lập mảng gồm n số nguyên ngẫu nhiên bằng
// constructor
// ▪ Xuất mảng ra màn hình
// ▪ Tìm số âm lớn nhất
// ▪ Đếm lần xuất hiện của một số nguyên x
// ▪ Kiểm tra mảng có giảm dần không
// ▪ Sắp xếp mảng tăng dần

#include <iostream>
#include <vector>
#include <cstdlib> // Thư viện cho rand()
#include <ctime>   // Thư viện cho time()
#include <algorithm> // Thư viện cho sort()
using namespace std;

class cArray {
private:
    vector<int> arr; // Mảng chứa các số nguyên

public:
    // Constructor khởi tạo mảng với n số nguyên ngẫu nhiên
    cArray(int n) {
        srand(time(0)); // Khởi tạo seed cho hàm rand()
        for (int i = 0; i < n; ++i) {
            int num = rand() % 201 - 100; // Sinh số ngẫu nhiên trong khoảng [-100, 100]
            arr.push_back(num);
        }
    }

    // Hàm xuất mảng ra màn hình
    void xuatMang() const {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Hàm tìm số âm lớn nhất trong mảng
    int timSoAmLonNhat() const {
        int soAmLonNhat = INT_MIN;
        bool coSoAm = false;

        for (int num : arr) {
            if (num < 0 && num > soAmLonNhat) {
                soAmLonNhat = num;
                coSoAm = true;
            }
        }

        if (!coSoAm) {
            cout << "Mảng không có số âm." << endl;
            return -1; // Không có số âm
        }

        return soAmLonNhat;
    }

    // Hàm đếm số lần xuất hiện của số nguyên x
    int demLanXuatHien(int x) const {
        int count = 0;
        for (int num : arr) {
            if (num == x) {
                ++count;
            }
        }
        return count;
    }

    // Hàm kiểm tra mảng có giảm dần hay không
    bool kiemTraGiamDan() const {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // Hàm sắp xếp mảng tăng dần
    void sapXepTangDan() {
        sort(arr.begin(), arr.end());
    }
};

// Chương trình chính minh họa các chức năng của lớp cArray
int main() {
    int n, x;

    cout << "Nhập số phần tử của mảng: ";
    cin >> n;

    cArray mang(n);

    cout << "Mảng ban đầu: ";
    mang.xuatMang();

    // Tìm số âm lớn nhất
    int soAmLonNhat = mang.timSoAmLonNhat();
    if (soAmLonNhat != -1) {
        cout << "Số âm lớn nhất trong mảng: " << soAmLonNhat << endl;
    }

    // Đếm số lần xuất hiện của x
    cout << "Nhập số nguyên cần đếm: ";
    cin >> x;
    int soLanXuatHien = mang.demLanXuatHien(x);
    cout << "Số lần xuất hiện của " << x << ": " << soLanXuatHien << endl;

    // Kiểm tra mảng có giảm dần hay không
    if (mang.kiemTraGiamDan()) {
        cout << "Mảng giảm dần." << endl;
    } else {
        cout << "Mảng không giảm dần." << endl;
    }

    // Sắp xếp mảng tăng dần và xuất ra
    cout << "Mảng sau khi sắp xếp tăng dần: ";
    mang.sapXepTangDan();
    mang.xuatMang();

    return 0;
}
