// Bài tập 2: Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first 
#define se second 

// Structure of fraction
typedef pair <ll, ll> Fraction;

// Shorten
Fraction simplify (Fraction f) {
    ll gcd = __gcd (abs(f.fi), abs(f.se));
    return make_pair (f.fi / gcd, f.se / gcd);
} 

//Max
bool Max(Fraction x, Fraction y) {
    return (x.fi * y.se > y.fi * x.se);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 
    
    Fraction x, y;
    
    // Insert 2 fractions
    cin >> x.fi >> x.se;
    cin >> y.fi >> y.se;
    
    
    // Shorten
    x = simplify(x);
    y = simplify(y);
    
    // Comparative
    if (Max(x, y)) {
        cout << x.fi << "/" << x.se << " is larger\n";
    } else {
        cout << y.fi << "/" << y.se << " is larger\n";
    }
    
    return 0;
}
