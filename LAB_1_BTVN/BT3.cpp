/*
Bài tập 3: Cho một mảng gồm n phân số, mỗi phân số có dạng a_i / b_i với i từ 1 đến m.
Nhiệm vụ của bạn là tìm một tập hợp con các phân số sao cho tích của các phân số
trong tập hợp con bằng một phân số đích a_k / b_k đã cho. Trong trường hợp có nhiều
tập hợp con thoả mãn điều kiện, bạn cần chọn tập hợp con có số lượng phần tử ít nhất.
Nếu không có tập hợp con nào thoả mãn, không xuất ra kết quả nào. Để giải bài toán,
bạn cần thực hiện các bước sau: nhập số lượng phân số n, nhập các phân số, và nhập
phân số đích a_k / b_k. Sau đó, tìm và xuất tập hợp con có tích bằng phân số đích, sắp
xếp các phân số trong tập hợp con theo thứ tự từ bé đến lớn. Lưu ý rằng không cần rút
gọn các phân số khi nhập vào.
*/

#include <bits/stdc++.h>
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

// Hàm để so sánh hai phân số bằng giá trị thực
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

// Hàm để tìm tập hợp con có tích bằng phân số đích
// Hàm để tìm tập hợp con có tích bằng phân số đích
bool findSubset(const vector<Fraction>& fractions, const Fraction& target, vector<Fraction>& result) {
    int n = fractions.size();
    int minSize = numeric_limits<int>::max(); // Số lượng phần tử nhỏ nhất trong tập hợp con

    // Sử dụng bitmask để tìm tất cả các tập hợp con
    for (int mask = 1; mask < (1 << n); ++mask) {
        Fraction product = {1, 1}; // Khởi tạo tích bằng 1/1
        vector<Fraction> subset;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // Nếu phần tử i nằm trong tập hợp con
                product.tu *= fractions[i].tu;
                product.mau *= fractions[i].mau;
                subset.push_back(fractions[i]);
            }
        }

        // Kiểm tra xem tích của tập hợp con có bằng với phân số đích không
        // Sử dụng điều kiện không cần rút gọn phân số
        if (product.tu * target.mau == target.tu * product.mau) {
            if (subset.size() < minSize) {
                minSize = subset.size();
                result = subset; // Cập nhật tập hợp con
            }
        }
    }

    return minSize != numeric_limits<int>::max();
}


int main() {
    int n;
    cout << "Nhap so luong phan so n: ";
    cin >> n;

    vector<Fraction> fractions(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        fractions[i] = inputFraction();
    }

    // Nhập phân số đích
    cout << "Nhap phan so dich: " << endl ;
    Fraction target = inputFraction();

    vector<Fraction> result;
    // Tìm tập hợp con có tích bằng phân số đích
    if (findSubset(fractions, target, result)) {
        // Sắp xếp các phân số trong tập hợp con theo thứ tự từ bé đến lớn
        sort(result.begin(), result.end(), [](const Fraction& a, const Fraction& b) {
            return fractionValue(a) < fractionValue(b);
        });

        // In kết quả
        cout << "Tap hop con co tich bang " << target.tu << "/" << target.mau << " la: " << endl;
        for (const auto& frac : result) {
            cout << frac.tu << "/" << frac.mau << " ";
        }
        cout << endl;
    } else {
        cout << "Khong co tap hop con nao thoat man yeu cau." << endl;
    }

    return 0;
}
