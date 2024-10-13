/*
Giả sử mỗi đối tượng sách trong hệ thống thư viện có các thuộc tính sau:
Mã sách, Tên sách, Năm xuất bản, Tổng số trang.
Hãy xây dựng lớp cBook với các thuộc tính như trên và các phương thức
cần thiết sau:
▪ Thiết lập thông tin sách
▪ Nhập thông tin cho đối tượng sách từ bàn phím
▪ Xuất thông tin đối tượng sách ra màn hình
▪ Truy vấn và cập nhật thông tin
Xây dựng lớp cListBook để quản lý danh sách các đối tượng sách và thực
hiện các yêu cầu sau:
▪ Nhập danh sách các đối tượng sách
▪ Xuất danh sách các đối tượng sách
▪ Cho biết thông tin sách nào được xuất bản gần đây nhất
*/

#include <bits/stdc++.h>
using namespace std;

class cBook {
private:
    string maSach;
    string tenSach;
    int namXuatBan;
    int tongSoTrang;

public:
    // 1. Hàm khởi tạo không tham số
    cBook() : maSach(""), tenSach(""), namXuatBan(0), tongSoTrang(0) {}

    // 2. Hàm khởi tạo có tham số
    cBook(string ma, string ten, int nam, int soTrang) 
        : maSach(ma), tenSach(ten), namXuatBan(nam), tongSoTrang(soTrang) {}

    // 3. Thiết lập thông tin sách
    void thietLapThongTin(string ma, string ten, int nam, int soTrang) {
        maSach = ma;
        tenSach = ten;
        namXuatBan = nam;
        tongSoTrang = soTrang;
    }

    // 4. Nhập thông tin sách từ bàn phím
    void nhapThongTin() {
        cout << "Nhap ma sach: ";
        cin >> maSach;
        cout << "Nhap ten sach: ";
        cin.ignore(); // Xóa bộ đệm để nhập chuỗi
        getline(cin, tenSach);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
        cout << "Nhap tong so trang: ";
        cin >> tongSoTrang;
    }

    // 5. Xuất thông tin sách ra màn hình
    void xuatThongTin() const {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Nam xuat ban: " << namXuatBan << endl;
        cout << "Tong so trang: " << tongSoTrang << endl;
    }

    // 6. Truy vấn thông tin
    int getNamXuatBan() const {
        return namXuatBan;
    }

    // 7. Cập nhật thông tin sách
    void capNhatThongTin(string ten, int nam, int soTrang) {
        tenSach = ten;
        namXuatBan = nam;
        tongSoTrang = soTrang;
    }
};

// Lớp quản lý danh sách sách
class cListBook {
private:
    vector<cBook> danhSachSach; // Danh sách các đối tượng sách

public:
    // 1. Nhập danh sách sách
    void nhapDanhSach() {
        int soLuong;
        cout << "Nhap so luong sach: ";
        cin >> soLuong;
        for (int i = 0; i < soLuong; i++) {
            cout << "Nhap thong tin cho cuon sach thu " << i + 1 << ":" << endl;
            cBook sach;
            sach.nhapThongTin();
            danhSachSach.push_back(sach);
        }
    }

    // 2. Xuất danh sách sách
    void xuatDanhSach() const {
        cout << "Danh sach cac cuon sach:" << endl;
        for (size_t i = 0; i < danhSachSach.size(); i++) {
            cout << "Thong tin cuon sach thu " << i + 1 << ":" << endl;
            danhSachSach[i].xuatThongTin();
        }
    }

    // 3. Tìm sách được xuất bản gần đây nhất
    void sachGanNhat() const {
        if (danhSachSach.empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        int viTriGanNhat = 0;
        for (size_t i = 1; i < danhSachSach.size(); i++) {
            if (danhSachSach[i].getNamXuatBan() > danhSachSach[viTriGanNhat].getNamXuatBan()) {
                viTriGanNhat = i;
            }
        }

        cout << "Thong tin cuon sach duoc xuat ban gan nhat:" << endl;
        danhSachSach[viTriGanNhat].xuatThongTin();
    }
};

int main() {
    cListBook listBook;

    // Nhập danh sách các đối tượng sách
    listBook.nhapDanhSach();

    // Xuất danh sách các đối tượng sách
    listBook.xuatDanhSach();

    // Tìm và xuất thông tin sách được xuất bản gần đây nhất
    listBook.sachGanNhat();

    return 0;
}
