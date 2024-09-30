#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846

// Hàm tính giá trị sin(x) bằng chuỗi Taylor
double calculateSine(double radians) {
    double term = radians;
    double sineValue = term; // Khởi tạo giá trị sin ban đầu là hạng tử đầu
    int iteration = 1;

    // Vòng lặp tính toán các hạng tử cho đến khi độ chính xác đạt yêu cầu
    while (fabs(term) >= 0.00001) { // Độ chính xác 0.00001
        term = (-term * radians * radians) / ((2 * iteration) * (2 * iteration + 1)); // Hạng tử tiếp theo
        sineValue += term; // Cộng dồn vào tổng
        iteration++;
    }

    return sineValue;
}

int main() {
    double angleInDegrees;
    cout << "Nhập giá trị góc (đơn vị độ từ 0 -> 180): ";
    cin >> angleInDegrees;

    // Chuyển đổi góc từ độ sang radian
    double angleInRadians = angleInDegrees * PI / 180.0;

    // Tính sin của góc bằng radian
    double sineResult = calculateSine(angleInRadians);
    cout << "Giá trị của sin(" << angleInDegrees << " độ) là: " << sineResult << endl;

    return 0;
}
