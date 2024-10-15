#include <iostream>
#include "List.h"

int main() {
    List list;
    int n;
    
    while (true) {
        std::cin >> n; // Nhập chỉ thị từ người dùng
        if (n == -1) { // Nhảy đến B3
            break;
        }

        double x, y;
        switch (n) {
            case 0:
                std::cin >> x; // Nhập phần tử x
                list.add(x);
                break;
            case 1:
                std::cin >> x; // Nhập phần tử x
                list.removeFirst(x);
                break;
            case 2:
                std::cin >> x; // Nhập phần tử x
                list.removeAll(x);
                break;
            case 3:
                std::cin >> x >> y; // Nhập x và y
                list.update(static_cast<int>(x), y);
                break;
        }
    }
    
    list.print(); // In ra list hiện tại
    return 0;
}
