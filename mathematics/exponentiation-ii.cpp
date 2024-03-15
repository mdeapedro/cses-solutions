#include <bits/stdc++.h>
using namespace std;

long long pwr(long long a, long long x, int mod) {
    long long r = 1;
    while (x > 0) {
        if (x & 1) {
            r *= a;
            r %= mod;
        }
        a *= a;
        a %= mod;
        x >>= 1;
    }
    return r;
}

void solve() {
    const int M = 1e9+7;
    long long a, b, c;
    cin >> a >> b >> c;
    b = pwr(b, c, M-1);
    cout << pwr(a, b, M) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
