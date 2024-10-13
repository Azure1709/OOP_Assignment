//  Viết chương trình cho phép người dùng:
//   - Nhập vào thông tin của một học sinh gồm: mã học sinh (chuỗi), 
// họ tên, giới tính, điểm toán, điểm lý, điểm hóa.
//   - Tính điểm trung bình và xuất thông tin chi tiết của học
// sinh ra màn hình
#include <bits/stdc++.h>
using namespace std;

// Struct to store student's information
struct Student {
    string id;
    string name;
    string gender; 
    float math;
    float phys; 
    float chemistry;

    // Function to calculate average score
    float average() {
        return (math + phys + chemistry) / 3;
    }

    // Function to input student's information
    void input() {
        cout << "Nhap ma hoc sinh: ";
        cin >> id;
        cin.ignore(); // To handle the newline after entering the id
        cout << "Nhap ho va ten: ";
        getline(cin, name);
        cout << "Nhap gioi tinh: ";
        getline(cin, gender);
        cout << "Nhap diem Toan: ";
        cin >> math;
        cout << "Nhap diem Ly: ";
        cin >> phys;
        cout << "Nhap diem Hoa: ";
        cin >> chemistry;
    }

    // Function to display student's information
    void display() {
        cout << "\nMa hoc sinh: " << id << endl;
        cout << "Ho va ten: " << name << endl;
        cout << "Gioi tinh: " << gender << endl;
        cout << "Diem Toan: " << math << endl;
        cout << "Diem Ly: " << phys << endl;
        cout << "Diem Hoa: " << chemistry << endl;
        cout << "Diem trung binh: " << average() << endl;
    }
};

int main() {
    Student student;

    // Input student's information
    student.input();

    // Output student's information
    student.display();

    return 0;
}
