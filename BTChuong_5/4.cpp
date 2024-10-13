/*
❖ Một ma trận là một mảng hai chiều gồm m dòng
và n cột. Hãy khai báo và cài đặt lớp biểu diễn
khái niệm ma trận để thực hiện các yêu cầu sau:
❖ Tạo ma trận ngẫu nhiên m dòng, n cột
❖ Nhập ma trận m dòng n cột
❖ Operator cộng hai ma trận
❖ Operator nhân hai ma trận
❖ Viết chương trình cho phép tạo 2 ma trận, cộng,
trừ 2 ma trận và xuất kết quả ra màn hình.
*/

#include <bits/stdc++.h>
using namespace std;

class MaTran {
    int m, n; // Số dòng và số cột
    vector<vector<int>> a; // Mảng hai chiều để lưu ma trận

public:
    // Khởi tạo ma trận với m dòng, n cột
    MaTran(int m = 0, int n = 0) {
        this->m = m;
        this->n = n;
        a.resize(m, vector<int>(n, 0));
    }

    // Hàm nhập ma trận từ bàn phím
    friend istream& operator>>(istream& is, MaTran& mt) {
        cout << "Nhap ma tran co " << mt.m << " dong va " << mt.n << " cot:\n";
        for (int i = 0; i < mt.m; i++) {
            for (int j = 0; j < mt.n; j++) {
                cout << "a[" << i << "][" << j << "]: ";
                is >> mt.a[i][j];
            }
        }
        return is;
    }

    // Hàm xuất ma trận ra màn hình
    friend ostream& operator<<(ostream& os, const MaTran& mt) {
        for (int i = 0; i < mt.m; i++) {
            for (int j = 0; j < mt.n; j++) {
                os << mt.a[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    // Tạo ma trận ngẫu nhiên m dòng n cột
    void taoNgauNhien() {
        srand(time(NULL));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = rand() % 10; // Giá trị ngẫu nhiên từ 0 đến 9
            }
        }
    }

    // Định nghĩa toán tử cộng hai ma trận
    MaTran operator+(const MaTran& mt) {
        // Kiểm tra kích thước của hai ma trận
        if (m != mt.m || n != mt.n) {
            throw invalid_argument("Hai ma tran phai cung kich thuoc de cong!");
        }
        MaTran result(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result.a[i][j] = a[i][j] + mt.a[i][j];
            }
        }
        return result;
    }

    // Định nghĩa toán tử nhân hai ma trận
    MaTran operator*(const MaTran& mt) {
        if (n != mt.m) {
            throw invalid_argument("So cot ma tran thu nhat phai bang so dong ma tran thu hai!");
        }
        MaTran result(m, mt.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < mt.n; j++) {
                for (int k = 0; k < n; k++) {
                    result.a[i][j] += a[i][k] * mt.a[k][j];
                }
            }
        }
        return result;
    }
};

// Chương trình minh họa
int main() {
    // Nhập ma trận thứ nhất
    int m1, n1;
    cout << "Nhap so dong va cot cua ma tran thu nhat: ";
    cin >> m1 >> n1;
    MaTran mt1(m1, n1);
    cin >> mt1;

    // Nhập ma trận thứ hai
    int m2, n2;
    cout << "Nhap so dong va cot cua ma tran thu hai: ";
    cin >> m2 >> n2;
    MaTran mt2(m2, n2);
    cin >> mt2;

    // Hiển thị hai ma trận
    cout << "Ma tran thu nhat:\n" << mt1;
    cout << "Ma tran thu hai:\n" << mt2;

    // Cộng hai ma trận nếu có cùng kích thước
    try {
        MaTran tong = mt1 + mt2;
        cout << "Tong hai ma tran:\n" << tong;

    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    // Nhân hai ma trận nếu có thể
    try {
        MaTran tich = mt1 * mt2;
        cout << "Tich hai ma tran:\n" << tich;
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
