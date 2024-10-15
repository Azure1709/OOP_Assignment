/*
Chúng ta có một bức ảnh nhị phân dưới dạng ma trận kích thước m×nm
\times nm×n, trong đó mỗi phần tử có giá trị 0 hoặc 1. Bức ảnh này chứa các đối tượng
hình chữ nhật, với các hình chữ nhật có gốc tọa độ là góc trên bên trái và có tất cả các
phần tử bên trong là 1. Nhiệm vụ của bạn là tìm tất cả các hình chữ nhật trong bức ảnh,
với điều kiện kích thước tối thiểu là 2 x 2. Để giải quyết bài toán, bạn cần thực hiện các
bước sau: đầu tiên, nhập kích thước ma trận mmm và nnn, sau đó nhập ma trận nhị phân
kích thước m×nm \times nm×n. Cuối cùng, xác định và xuất danh sách các hình chữ 
nhật theo định dạng [x, y, w, h], trong đó x và y là tọa độ gốc của hình chữ nhật, và w
và h lần lượt là chiều rộng và chiều cao của hình chữ nhật. Danh sách các hình chữ nhật
cần được sắp xếp theo thứ tự từ trái sang phải và từ trên xuống dưới
*/

#include<bits/stdc++.h>
using namespace std;

// Khai bao kich thuoc ma tran
int n, m;

// Struct de luu ma tran
struct matrix {
    int A[2002][2002]; // Mang 2 chieu

    // Ham khoi tao ma tran
    void init() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> this->A[i][j]; // Nhap gia tri cho ma tran
            }
        }
    }

    // Ham xay dung ma tran luu tru tong
    void build() {
        for(int i = 1; i <= n + 1; i++) {
            for(int j = 1; j <= m + 1; j++) {
                this->A[i][j] += this->A[i - 1][j] + this->A[i][j - 1] - this->A[i - 1][j - 1]; // Tinh tong
            }
        }
    }

    // Ham lay tong cac phan tu trong hinh chu nhat
    int get_sum(int a, int b, int c, int d) {
        return this->A[c][d] - (a - 1 <= 0 ? 0 : this->A[a - 1][d]) - (b - 1 <= 0 ? 0 : this->A[c][b - 1]) + (a - 1 <= 0 || b - 1 <= 0 ? 0 : this->A[a - 1][b - 1]);
    }
};

// Khai bao ma tran A
matrix A;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Nhap kich thuoc ma tran
    cin >> m >> n;
    A.init(); // Khoi tao ma tran
    A.build(); // Xay dung ma tran luu tru tong

    // Duyet qua tat ca cac diem trong ma tran
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= m; y++) {
            for(int px = x + 1; px <= n; px++) {
                for(int py = y + 1; py <= m; py++) {
                    // Kiem tra xem hinh chu nhat co phai la hinh chu nhat toan 1 khong
                    if (A.get_sum(x - 1, y - 1, px + 1, py + 1) == (px - x + 1) * (py - y + 1) && 
                        A.get_sum(x, y, px, py) == (px - x + 1) * (py - y + 1)) {
                        // In ra vi tri va kich thuoc hinh chu nhat
                        cout << "[" << y - 1 << "," << x - 1 << "," << (py - 1) - (y - 1) + 1 << "," << (px - 1) - (x - 1) + 1 << "]" << '\n';
                    }
                }
            }
        }
    }
}
