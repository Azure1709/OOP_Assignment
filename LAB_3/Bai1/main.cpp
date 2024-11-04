#include <iostream>
#include "PhanSo.h"

int main() {
    PhanSo ps1(1, 2), ps2(3, 4);

    std::cout << "Phan so 1: " << ps1 << "\n";
    std::cout << "Phan so 2: " << ps2 << "\n";


    PhanSo sum = ps1 + ps2;
    std::cout << "Tong: " << sum << "\n";

    PhanSo diff = ps1 - ps2;
    std::cout << "Hieu: " << diff << "\n";

    PhanSo prod = ps1 * ps2;
    std::cout << "Tich: " << prod << "\n";

    PhanSo quot = ps1 / ps2;
    std::cout << "Thuong: " << quot << "\n";

    std::cout << "So sanh ps1 == ps2: " << (ps1 == ps2 ? "True" : "False") << "\n";

    return 0;
}
