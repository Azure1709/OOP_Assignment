// Cài đặt lớp số phức để biểu diễn khái niệm số phức (một
// số phức bao gồm hai thành phần: phần ảo, phần thực).
// Cho phép thực hiên các thao tác sau:
// - Tạo lập số phức khi biết phần thực và ảo
// - Thay đổi phần thực, phần ảo
// - Lấy giá trị phần thực, phần ảo
// - Nhập số phức
// - Xuất số phức
// - Công hai số phức.
// ❖ Viết chương trình minh họa
//  các chức năng của
//  lớp số phức

#include <iostream>
using namespace std;

class SoPhuc {
private:
    float phanThuc; 
    float phanAo;   

public:
    // Constructor mặc định
    SoPhuc() {
        phanThuc = 0;
        phanAo = 0;
    }

    // Constructor với tham số đầu vào cho phần thực và phần ảo
    SoPhuc(float thuc, float ao) {
        phanThuc = thuc;
        phanAo = ao;
    }

    // Hàm nhập số phức
    void nhap() {
        cout << "Nhập phần thực: ";
        cin >> phanThuc;
        cout << "Nhập phần ảo: ";
        cin >> phanAo;
    }

    // Hàm xuất số phức
    void xuat() const {
        if (phanAo < 0)
            cout << phanThuc << " - " << -phanAo << "i" << endl;
        else
            cout << phanThuc << " + " << phanAo << "i" << endl;
    }

    // Hàm thay đổi phần thực
    void thayDoiPhanThuc(float thuc) {
        phanThuc = thuc;
    }

    // Hàm thay đổi phần ảo
    void thayDoiPhanAo(float ao) {
        phanAo = ao;
    }

    // Hàm lấy giá trị phần thực
    float layPhanThuc() const {
        return phanThuc;
    }

    // Hàm lấy giá trị phần ảo
    float layPhanAo() const {
        return phanAo;
    }

    // Hàm cộng hai số phức
    SoPhuc cong(const SoPhuc& sp) const {
        return SoPhuc(phanThuc + sp.phanThuc, phanAo + sp.phanAo);
    }
};

// Chương trình minh họa chức năng của lớp số phức
int main() {
    // Tạo hai số phức
    SoPhuc sp1, sp2;

    // Nhập hai số phức
    cout << "Nhập số phức thứ nhất:" << endl;
    sp1.nhap();
    cout << "Nhập số phức thứ hai:" << endl;
    sp2.nhap();

    // Xuất hai số phức
    cout << "\nSố phức thứ nhất: ";
    sp1.xuat();
    cout << "Số phức thứ hai: ";
    sp2.xuat();

    // Cộng hai số phức
    SoPhuc spTong = sp1.cong(sp2);

    // Xuất kết quả cộng hai số phức
    cout << "\nTổng hai số phức là: ";
    spTong.xuat();

    return 0;
}
