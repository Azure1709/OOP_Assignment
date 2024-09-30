// Viết chương trình nhập vào tọa độ 2 điểm trong mặt phẳng Oxy. 
// Tính khoảng cách giữa chúng và xuất kết quả.

#include <bits/stdc++.h>
using namespace std;

class Point {
private:
    float x, y;

public:
    void input() {
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
    }

    // Hàm lấy tọa độ x
    float getX() const {
        return x;
    }

    // Hàm lấy tọa độ y
    float getY() const {
        return y;
    }
};

// Hàm tính khoảng cách giữa hai điểm
float distance(const Point& p1, const Point& p2) {
    float dx = p1.getX() - p2.getX();
    float dy = p1.getY() - p2.getY();
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1, p2;

    // Nhập tọa độ của hai điểm
    cout << "First point: " << endl;
    p1.input();
    cout << "Second point: " << endl;
    p2.input();

    // Tính khoảng cách giữa hai điểm
    float dist = distance(p1, p2);

    // Xuất kết quả
    cout << "Distance: " << dist << endl;

    return 0;
}
