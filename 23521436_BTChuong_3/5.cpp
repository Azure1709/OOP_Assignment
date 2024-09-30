// Định nghĩa lớp cHocSinh gồm các thuộc tính:
// mã, họ tên, giới tính, năm sinh, điểm trung bình và
// các phương thức cần thiết.
// Viết chương trình cho phép người dùng nhập thông
// tin 2 học sinh.
// - Cho biết học sinh nào có điểm trung bình cao hơn.
// - Cho biết học sinh nào có tuổi nhỏ hơn

#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string id;
    string name;
    string gender;
    int birthYear;
    float avgScore;

public:
    void inputInfo();
    void displayInfo();
    float getAvgScore();
    int getBirthYear();
    string getName();
};

void Student::inputInfo() {
    cout << "Enter student ID: "; 
    cin >> id;
    cin.ignore(); // Ignore newline character
    cout << "Enter full name: "; 
    getline(cin, name);
    cout << "Enter gender: "; 
    cin >> gender;
    cout << "Enter birth year: "; 
    cin >> birthYear;
    cout << "Enter average score: "; 
    cin >> avgScore;
}

void Student::displayInfo() {
    cout << "Student ID: " << id << '\n';
    cout << "Full name: " << name << '\n';
    cout << "Gender: " << gender << '\n';
    cout << "Birth year: " << birthYear << '\n';
    cout << "Average score: " << avgScore << '\n';
}

float Student::getAvgScore() {
    return avgScore;
}

int Student::getBirthYear() {
    return birthYear;
}

string Student::getName() {
    return name;
}

void compareAvgScore(Student s1, Student s2) {
    float avg1 = s1.getAvgScore();
    float avg2 = s2.getAvgScore();
    string name1 = s1.getName();
    string name2 = s2.getName();

    if (avg1 > avg2)
        cout << "Student " << name1 << " has a higher average score than student " << name2 << '\n';
    else if (avg1 < avg2)
        cout << "Student " << name2 << " has a higher average score than student " << name1 << '\n';
    else
        cout << "Both students " << name1 << " and " << name2 << " have the same average score\n";
}

void compareAge(Student s1, Student s2) {
    int age1 = 2024 - s1.getBirthYear(); // Assume current year is 2024
    int age2 = 2024 - s2.getBirthYear();
    string name1 = s1.getName();
    string name2 = s2.getName();

    if (age1 > age2)
        cout << "Student " << name1 << " is older than student " << name2 << '\n';
    else if (age1 < age2)
        cout << "Student " << name2 << " is older than student " << name1 << '\n';
    else
        cout << "Both students " << name1 << " and " << name2 << " are of the same age\n";
}

int main() {
    Student student1, student2;

    cout << "Enter information for the first student:\n";
    student1.inputInfo();

    cout << "\nEnter information for the second student:\n";
    student2.inputInfo();

    cout << "\nComparing average scores:\n";
    compareAvgScore(student1, student2);

    cout << "\nComparing ages:\n";
    compareAge(student1, student2);

    return 0;
}
