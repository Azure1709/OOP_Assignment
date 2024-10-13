// Viết chương trình nhập tọa độ tâm và bán kính của
// đường tròn. Tính diện tích và chu vi của đường tròn.

#include<bits/stdc++.h>
using namespace std;
// Circular center R(x,y) d=2r
class Rline {
    private:
        int x, y;
        float r;
    public:
        Rline() {
            x = 0;
            y = 0;
            r = 0;
        }
        Rline(int Ox, int Oy, float radius) {
            x = Ox;
            y = Oy;
            r = radius;
        }
        void input();
        void output();
        float acreage();
        float perimeter();
};

void Rline::input() {
    cout << "Enter circular inf:\n";
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;
    cout << "r: "; cin >> r;
}

void Rline:: output() {
    cout << "Area of ​​circle: " << acreage() << "\n";
    cout << "Circumference of circle: " << perimeter() << "\n";
}

float Rline :: acreage() {
    return 3.14 * r * r;
}

float Rline :: perimeter() {
    return 2 * 3.14 * r;
}

int main() {
    Rline TT;
    TT.input();
    TT.output();
    return 0;
}