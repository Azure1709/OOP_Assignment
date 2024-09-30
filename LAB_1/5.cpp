#include <iostream>

/// các lưu ý :
/// 1)  năm nhuận sẽ có 366 ngày, năm bình thường sẽ có 365 ngày
/// 2)  Tháng 1, 3, 5, 7, 8, 10, 12 có 31 ngày
/// 3)  Tháng 4, 6, 9, 11 có 30 ngày
/// 4)  Tháng 2 sẽ có số ngày phụ thuộc vào năm


using namespace std;

// Hàm kiểm tra năm nhuận
// Năm nhuận là năm chia hết cho 4 nhưng không chia hết cho 100,
// hoặc chia hết cho 400. Điều này đảm bảo rằng những năm như 2000 là năm nhuận,
// nhưng những năm như 1900 không phải năm nhuận.

bool namNhuan(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Hàm trả về số ngày trong một tháng cụ thể
// Đối với tháng 2, nếu năm là năm nhuận, tháng này có 29 ngày,
// nếu không chỉ có 28 ngày. Các tháng khác có 30 hoặc 31 ngày như bình thường.

int soNgayTrongThang(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;

    else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;

    else if (month == 2) return namNhuan(year) ? 29 : 28;
}

// Hàm tính ngày kế tiếp
// Nếu ngày hiện tại chưa phải là ngày cuối cùng của tháng,
// chỉ cần tăng ngày lên 1. Nhưng nếu ngày hiện tại là ngày cuối cùng
// của tháng (dựa trên số ngày của tháng đó), thì cần chuyển sang ngày 1
// của tháng kế tiếp. Nếu tháng hiện tại là tháng 12, ngày kế tiếp sẽ là 1/1 của năm tiếp

void ngayKeTiep(int &day, int &month, int &year) {
    int soNgay = soNgayTrongThang(month, year);
    if (day < soNgay) {
        day++;
    } else {
        day = 1;
        if (month < 12) {
            month++;
        } else {
            month = 1;
            year++;
        }
    }
}

// Hàm tính ngày trước đó
// Nếu ngày hiện tại không phải là ngày đầu tiên của tháng, giảm ngày đi 1.
// Nếu là ngày đầu tiên của tháng, thì cần chuyển về ngày cuối cùng của tháng trước đó.
// Nếu tháng hiện tại là tháng 1, thì ngày trước đó sẽ là 31/12 của năm trước.

void ngayTruocDo(int &day, int &month, int &year) {
    if (day > 1) {
        day--;
    } else {
        if (month > 1) {
            month--;
            day = soNgayTrongThang(month, year);
        } else {
            month = 12;
            day = 31;
            year--;
        }
    }
}

// Hàm tính xem đó là ngày thứ bao nhiêu trong năm
// Hàm này cộng dồn số ngày từ các tháng trước đó, và thêm ngày hiện tại để tính xem
// ngày đó là ngày thứ bao nhiêu trong năm. Năm nhuận ảnh hưởng đến tháng 2,
// vì tháng 2 có 29 ngày thay vì 28.

int tinhNgayThuBaoNhieu(int day, int month, int year) {
    int ngayThu = day;
    for (int i = 1; i < month; i++) {
        ngayThu += soNgayTrongThang(i, year);
    }
    return ngayThu;
}

int main() {
    int day, month, year;

    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    // Tính ngày kế tiếp
    int nextDay = day, nextMonth = month, nextYear = year;
    ngayKeTiep(nextDay, nextMonth, nextYear);
    cout << "Ngay ke tiep la: " << nextDay << "/" << nextMonth << "/" << nextYear << endl;

    // Tính ngày trước đó
    int prevDay = day, prevMonth = month, prevYear = year;
    ngayTruocDo(prevDay, prevMonth, prevYear);
    cout << "Ngay truoc do la: " << prevDay << "/" << prevMonth << "/" << prevYear << endl;

    // Tính ngày đó là ngày thứ bao nhiêu trong năm
    int ngayThuBaoNhieu = tinhNgayThuBaoNhieu(day, month, year);
    cout << "Ngay " << day << "/" << month << "/" << year << " la ngay thu " << ngayThuBaoNhieu << " trong nam." << endl;

    return 0;
}

