#include <iostream>
#include "Polygon.h"
using namespace std;

int main() {
    int n;
    
    // Nhập số điểm của đa giác
    cin >> n;
    
    // Kiểm tra điều kiện số điểm phải lớn hơn 2
    if (n <= 2) {
        cout << "Invalid number of points" << endl;
        return 1;
    }

    // Tạo đối tượng đa giác
    Polygon polygon(n);

    // Nhập tọa độ các điểm của đa giác
    polygon.input();

    // Xuất diện tích của đa giác
    polygon.displayArea();

    return 0;
}
