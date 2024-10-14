/*
Bài tập 2: Để giải bài toán tìm phân số lớn thứ k và bé thứ k trong một mảng gồm n
phân số, trước tiên, ta cần nhập số lượng phân số n và số nguyên dương k từ bàn phím.
Sau đó, các phân số được nhập vào, có thể nhập trên cùng một dòng hoặc mỗi phân số
trên một dòng riêng. Sau khi hoàn thành việc nhập liệu, chương trình sẽ tìm và xuất ra
phân số lớn thứ k và phân số bé thứ k trong mảng, theo định dạng: tử số của phân số lớn
thứ k / mẫu số của phân số lớn thứ k và tử số của phân số bé thứ k / mẫu số của phân số
bé thứ k. Nếu không có phân số lớn thứ k hoặc bé thứ k, chương trình sẽ không xuất ra
gì. Lưu ý rằng không cần rút gọn các phân số khi nhập vào.
*/

#include <iostream>
#include <vector>
#include <algorithm> // để sử dụng hàm sort
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

// Hàm so sánh để sắp xếp các phân số
bool compareFractions(const Fraction& a, const Fraction& b) {
    return fractionValue(a) < fractionValue(b);
}

int main() {
    int n, k;
    cout << "Nhap so luong phan so n: ";
    cin >> n;
    cout << "Nhap so nguyen duong k: ";
    cin >> k;

    vector<Fraction> fractions(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        fractions[i] = inputFraction();
    }

    // Sắp xếp các phân số theo giá trị thực
    sort(fractions.begin(), fractions.end(), compareFractions);

    // Kiểm tra nếu k nằm trong phạm vi hợp lệ
    if (k > 0 && k <= n) {
        // Xuất phân số bé thứ k
        Fraction kthMin = fractions[k - 1]; // k - 1 vì chỉ số mảng bắt đầu từ 0
        cout << "Phan so be thu " << k << ": " << kthMin.tu << "/" << kthMin.mau << endl;

        // Xuất phân số lớn thứ k
        Fraction kthMax = fractions[n - k]; // n - k để lấy phân số lớn thứ k
        cout << "Phan so lon thu " << k << ": " << kthMax.tu << "/" << kthMax.mau << endl;
    } else {
        cout << "Khong co phan so thu " << k << endl;
    }

    return 0;
}
