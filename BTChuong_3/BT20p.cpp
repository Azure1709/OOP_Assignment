// Định nghĩa lớp cPhanSo biểu diễn khái niệm phân số gồm 2
// thành phần dữ liệu: tử số, mẫu số và các thao tác:
// - Nhập phân số
// - Khởi tạo tử số và mẫu số cho phân số
// - Xuất phân số
// - Lấy giá trị phấn số
// - Tính tổng 2 phân số
// Viết chương trình cho phép người dùng nhập vào 2 phân số,
// tính tổng 2 phân số và xuất kết quả ra màn hình dưới dạng
// phân số.

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Hàm tìm ước chung lớn nhất (GCD)
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    // Hàm rút gọn phân số
    void simplify() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
        // Đảm bảo mẫu số luôn dương
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor mặc định
    Fraction() : numerator(0), denominator(1) {}

    // Constructor với tham số
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    // Hàm nhập phân số
    void input() {
        cout << "Nhập tử số: ";
        cin >> numerator;
        do {
            cout << "Nhập mẫu số (khác 0): ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "Mẫu số không hợp lệ. Vui lòng nhập lại." << endl;
            }
        } while (denominator == 0);
    }

    // Hàm xuất phân số
    void display() {
        simplify();
        if (denominator == 1) {
            cout << numerator << endl;
        } else if (numerator == 0) {
            cout << 0 << endl;
        } else {
            cout << numerator << "/" << denominator << endl;
        }
    }

    // Hàm tính tổng hai phân số
    Fraction add(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }
};

int main() {
    cout << "Enter two fractions:" << endl;
    Fraction f1, f2;

    cout << "Enter the first fraction:" << endl;
    f1.input();

    cout << "Enter the second fraction:" << endl;
    f2.input();

    // Tính tổng
    Fraction result = f1.add(f2);

    // Hiển thị kết quả
    cout << "The sum of two fractions is: ";
    result.display();

    return 0;
}
