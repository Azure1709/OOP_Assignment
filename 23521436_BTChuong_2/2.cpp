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
    return (x.fi * y.se > x.fi * y.se);
}

// Math
Fraction sum(Fraction x, Fraction y) {
    Fraction ans = {x.fi * y.se + y.fi * x.se, x.se * y.se};
    return simplify(ans);
}

Fraction A[1009];
Fraction Max_array, Sum_array;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int size_array;
    cin >> size_array;
    Max_array = make_pair(-1e9, 1);
    Sum_array = make_pair(0, 1);

    for (int i = 1; i <= size_array; ++i) {
        cin >> A[i].fi >> A[i].se;
        A[i] = simplify(A[i]);


        if (Max(Max_array, A[i])) {
            Max_array = A[i];
        }

        Sum_array = sum(Sum_array, A[i]);
    }

    cout << "Max Fraction " << Max_array.fi << "/" << Max_array.se << endl;
    cout << "Sum " << Sum_array.fi << "/" << Sum_array.se << endl;

    return 0;
}
