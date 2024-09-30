// Viết chương trình nhập vào 2 phân số, tính tổng, hiệu, tích, thương và xuất kết quả
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
   
// Math
Fraction sum(Fraction x, Fraction y) {
    Fraction ans = {x.fi * y.se + y.fi * x.se, x.se * y.se};
    return simplify(ans);
}

Fraction sub(Fraction x, Fraction y) {
    Fraction ans = {x.fi * y.se - y.fi * x.se, x.se * y.se};
    return simplify(ans);
}

Fraction mul(Fraction x, Fraction y) {
    Fraction ans = {x.fi * y.fi, x.se * y.se};
    return simplify(ans);
}

Fraction div(Fraction x, Fraction y) {
    Fraction ans = {x.fi * y.se, x.se * y.fi};
    return simplify(ans);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    Fraction x, y;
    cin >> x.fi >> x.se;
    cin >> y.fi >> y.se;
    Fraction Sum = sum (x,y);
    Fraction Sub = sub (x,y);
    Fraction Mul = mul (x,y);
    Fraction Div = div (x,y);
    cout << Sum.fi << "/" << Sum.se << "\n";
    cout << Sub.fi << "/" << Sub.se << "\n";
    cout << Mul.fi << "/" << Mul.se << "\n";
    cout << Div.fi << "/" << Div.se << "\n";
    return 0;
}