#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 1000111;

ll POW[maxn], hashT[maxn], T[maxn], P[maxn];
int lenT, lenP;

// Thuật toán Hash để tìm các đoạn con phù hợp
ll getHashT(int i, int j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    // Khởi tạo dữ liệu ngẫu nhiên cho việc kiểm thử
    srand(time(0)); // Đặt seed cho việc sinh ngẫu nhiên

    // Sinh độ dài ngẫu nhiên cho chuỗi P và T
    lenP = rand() % 10 + 1; // Độ dài P từ 1 đến 10
    lenT = rand() % 100 + lenP; // Độ dài T từ lenP đến lenP + 100

    // Sinh dữ liệu ngẫu nhiên cho chuỗi P và T
    for (int i = 1; i <= lenP; i++)
        P[i] = rand() % 26 + 97; // Các ký tự từ 'a' đến 'z'
    for (int i = 1; i <= lenT; i++)
        T[i] = rand() % 26 + 97;

    // Xuất chuỗi P và T
    cout << "Chuoi P: ";
    for (int i = 1; i <= lenP; i++)
        cout << (char)P[i];
    cout << endl;

    cout << "Chuoi T: ";
    for (int i = 1; i <= lenT; i++)
        cout << (char)T[i];
    cout << endl << endl;

    // Tính giá trị POW cho các số mũ
    POW[0] = 1;
    for (int i = 1; i <= lenT; i++)
        POW[i] = (POW[i - 1] * base) % MOD;

    // Tính giá trị hash cho chuỗi T
    for (int i = 1; i <= lenT; i++)
        hashT[i] = (hashT[i - 1] * base + T[i] + 1) % MOD;

    // Tính giá trị hash cho chuỗi P
    ll hashP = 0;
    for (int i = 1; i <= lenP; i++)
        hashP = (hashP * base + P[i] + 1) % MOD;

    // Tìm các vị trí khớp
    vector<int> V;
    for (int i = 1; i <= lenT - lenP + 1; i++) {
        if (hashP == getHashT(i, i + lenP - 1))
            V.push_back(i - 1);
    }

    // Kết quả
    cout << "So vi tri khop: " << V.size() << endl;
    for (int v : V)
        cout << v << " ";
    cout << endl;

    return 0;
}
