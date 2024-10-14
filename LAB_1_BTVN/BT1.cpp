/*
Bài tập 1: Để tìm phân số lớn nhất và nhỏ nhất trong một mảng phân số, trước tiên, cần
nhập vào số lượng phân số n. Sau đó, lần lượt nhập tử số và mẫu số của từng phân số.
Khi mẫu số của bất kỳ phân số nào được nhập bằng 0, người dùng phải nhập lại giá trị
hợp lệ cho mẫu số. Sau khi hoàn tất việc nhập liệu, kết quả sẽ xuất ra hai phân số có giá
trị nhỏ nhất và lớn nhất theo định dạng: tử số nhỏ nhất / mẫu số nhỏ nhất và tử số lớn
nhất / mẫu số lớn nhất. Lưu ý rằng trong bài toán này, không cần thiết phải rút gọn các
phân số.
*/

#include <iostream>
#include <vector>
using namespace std;

// Struct để lưu phân số
struct Fraction {
    int tu;   
    int mau; 

    // Hàm chuẩn hóa phân số để đảm bảo mẫu số luôn dương
    void normalize() {
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
};

// Hàm để so sánh hai phân số
double fractionValue(const Fraction& frac) {
    return static_cast<double>(frac.tu) / frac.mau;
}

// Hàm nhập phân số
Fraction inputFraction() {
    Fraction frac;
    cout << "Nhap tu so: ";
    cin >> frac.tu;
    do {
        cout << "Nhap mau so: ";
        cin >> frac.mau;
        if (frac.mau == 0) {
            cout << "Mau so khong hop le, vui long nhap lai." << endl;
        }
    } while (frac.mau == 0);
    frac.normalize(); // Chuẩn hóa phân số ngay sau khi nhập
    return frac;
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<Fraction> fractions(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        fractions[i] = inputFraction();
    }

    // Khởi tạo giá trị nhỏ nhất và lớn nhất
    Fraction minFrac = fractions[0];
    Fraction maxFrac = fractions[0];

    // Tìm phân số nhỏ nhất và lớn nhất
    for (int i = 1; i < n; ++i) {
        if (fractionValue(fractions[i]) < fractionValue(minFrac)) {
            minFrac = fractions[i];
        }
        if (fractionValue(fractions[i]) > fractionValue(maxFrac)) {
            maxFrac = fractions[i];
        }
    }

    // In kết quả
    cout << "Phan so nho nhat: " << minFrac.tu << "/" << minFrac.mau << endl;
    cout << "Phan so lon nhat: " << maxFrac.tu << "/" << maxFrac.mau << endl;

    return 0;
}