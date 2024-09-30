// Viết chương trình nhập họ tên, điểm toán, điểm văn
// của một học sinh. Tính điểm trung bình, xếp loại và
// xuất kết quả.

#include<bits/stdc++.h>
using namespace std;

class Student {
private:
    string fullName;
    float mathScore;
    float literatureScore;

public:
    void input();
    void output();
    float averageScore();
    string gradeClassification(float avgScore);
};

void Student::input() {
    cout << "Enter full name: ";
    getline(cin, fullName);
    cout << "Enter Math score: ";
    cin >> mathScore;
    cout << "Enter Literature score: ";
    cin >> literatureScore;
}

void Student::output() {
    float avgScore = round(averageScore() * 100) / 100;
    cout << fixed << setprecision(2); // Chỉ hiện 2 chữ số thập phân
    cout << "Average score: " << avgScore << endl;
    cout << "Grade classification: " << gradeClassification(avgScore) << endl;
}

float Student::averageScore() {
    return (mathScore + literatureScore) / 2;
}

string Student::gradeClassification(float avgScore) {
    if (avgScore >= 8.0) {
        return "Excellent";
    } else if (avgScore >= 6.5) {
        return "Good";
    } else if (avgScore >= 5.0) {
        return "Average";
    } else {
        return "Poor";
    }
}

int main() 
{
    Student a;
    a.input();
    a.output();
}