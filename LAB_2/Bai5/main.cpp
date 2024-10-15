#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    float x, y;
    int n, command, direction;
    float distance;

    // Nhap vao diem ban dau
    cin >> x >> y;
    Point p(x, y);

    // Nhap so luong chi thi
    cin >> n;

    // Xu ly tung chi thi
    for (int i = 0; i < n; ++i) {
        cin >> command;
        switch (command) {
            case 1:
                p.doubleCoordinates();
                break;
            case 2:
                p.resetToOrigin();
                break;
            case 3:
                cin >> direction >> distance;
                p.translate(direction, distance);
                break;
            default:
                // Khong lam gi ca neu chi thi khong hop le
                break;
        }
    }

    // Xuat ra thong tin diem cuoi cung
    p.display();

    return 0;
}
