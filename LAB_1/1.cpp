// Bài tập 1: Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả
#include <bits/stdc++.h>
using namespace std;

struct Fraction {
    int numerator, denominator;

    // Hàm rút gọn phân số
    void shorten() {
        if (denominator == 0) {
            cout << "Error fraction\n";
            return;
        }
        
        
    // Sử dụng __gcd để tính ước số chung lớn nhất
    int temp = __gcd(numerator, denominator);
    numerator /= temp;
    denominator /= temp;

    // Đảm bảo mẫu số luôn dương
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    // Kiểm tra nếu tử và mẫu cùng âm thì chuyển cả hai thành dương
    if (numerator < 0 && denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    }
};

int main() {
    Fraction a;
    cout << "Insert Fraction: ";
    cin >> a.numerator >> a.denominator;
    a.shorten();
    cout << "Shorten Fraction: " << a.numerator << " / " << a.denominator << endl;
    return 0;
}
